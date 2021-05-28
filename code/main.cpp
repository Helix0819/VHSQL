#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <list>
//#include "dbms.h"
#include <unistd.h>
#include "file.h"

//#include "DDL.h"
#include "DB.h"
// include the sql parser
#include "SQLParser.h"


// contains printing utilities
#include "util/sqlhelper.h"

using namespace std;
//using column = std::pair<std::string,int>;

void othersql(string *DBName, string sqlWord)
{
    stringstream read(sqlWord);
    string word;
    string path;
    vector<string> other;

    while (read.rdbuf()->in_avail() != 0)
    {
        read >> word;
        other.push_back(word);
    }
    if (other.size() == 1 && *other.begin() == "exit")
    {
        exit(0);
    }
    if (other.size() == 2)
    {
    }
    else
    {
        cout << "I DO NOT UNDERSTAND" << endl;
        return;
    }
    if (*other.begin() == "use")
    {
    }
    else
    {
        cout << "I DO NOT UNDERSTAND" << endl;
        return;
    }
    path = "../data/" + *(--other.end());
    if (access(path.c_str(), F_OK) == 0)
    {
        *DBName = *(--other.end());
        cout << "ENTRY DATABASE " <<*DBName << endl;
    }
    else
    {
        cout << "DataBase not found" << endl;
        return;
    }
}

bool table_exists(std::string dbname, std::string tablename)
{
    std::string path = "../data/" + dbname + "/" + tablename + ".dat";
    std::string pathIdx = "../data/" + dbname + "/" + tablename + ".idx";
    if(!File::file_exists(path) || !File::file_exists(pathIdx))
        return false;
    else
        return true;
}

int main()
{

    //定义一个全局的库名
    std::string db;
    //定义一个全局的表名字
    std::string tb;

    while (1)
    {
        std::string query;

        hsql::SQLParserResult result;

        std::cout<<"VHSQL ";

        getline(std::cin, query);

        hsql::SQLParser::parse(query, &result);

        if (result.isValid())
        {
            auto stmt = (const hsql::SQLStatement *)result.getStatement(0);

            switch (stmt->type())
            {
            case hsql::kStmtSelect:
            {
                //调用select
                if (db.empty())
                {
                    cout << "BEFORE YOU SELECT, ENTRY A DATABASE FIRST" << endl;
                }
                else
                {
                    auto stmtSel = (const hsql::SelectStatement *)result.getStatement(0);
                    tb = stmtSel->fromTable->getName();
                    //检查表是否存在...
                    if(table_exists(db, tb)){
                        table t(tb, db);
                        t.select(stmtSel);
                    }else{
                        cout << "Table Not Found or Not Complete" << endl;
                    }
                }
            }

            break;
            case hsql::kStmtInsert:
            {
                if (db.empty())
                {
                    cout << "BEFORE YOU INSERT, ENTRY A DATABASE FIRST" << endl;
                }
                else
                {
                    std::cout << "insert" << std::endl;
                    auto stmtIns = (const hsql::InsertStatement *)result.getStatement(0);
                    tb = stmtIns->tableName;
                    if(table_exists(db, tb)){
                        table t(tb, db);
                        t.insert(stmtIns);
                        
                    }else{
                        std::cout << "Table Not Found or Not Complete" << std::endl;
                    }
                }
            }

            break;
                //类型转换....
            case hsql::kStmtCreate:
            {
                auto stmtCre = (const hsql::CreateStatement *)result.getStatement(0);
                if (stmtCre->schema == nullptr)
                {
                    //创建数据表
                    if (db.empty())
                    {
                        cout << "BEFORE YOU CREATE A TABLE, ENTRY A DATABASE FIRST" << endl;
                    }
                    else
                    {
                        DB database(db);
                        database.create_table(stmtCre);
                    }
                }
                else
                {
                    //创建数据库
                    DB database(stmtCre->schema);
                    database.createDB();
                    std::cout << "CREATE DATABASE SUCCESS" << std::endl;
                }
            }

            break;
                //类型转换....
            case hsql::kStmtDelete:
            {
                
                auto stmtDel = (const hsql::DeleteStatement*) result.getStatement(0);
                
                //检查表是否存在
                if (db.empty())
                {
                    cout << "BEFORE YOU DELETE, ENTRY A DATABASE FIRST" << endl;
                }else
                {
                    tb = stmtDel->tableName;
                    if(table_exists(db, tb)){
                        table t(tb,db);
                        t.del(stmtDel);
                    }else{
                        cout << "Table Not Found or Not Complete" << endl;
                    }  
                }
            }
            break;
                //类型转换....
            case hsql::kStmtDrop:
            {
                auto stmtDrop = (const hsql::DropStatement*) result.getStatement(0);
                //类型转换....
                if(stmtDrop->type == hsql::kDropTable){
                    if (db.empty())
                    {
                        cout << "BEFORE YOU DELETE, ENTRY A DATABASE FIRST" << endl;
                    }else
                    {
                        tb = stmtDrop->name;
                        DB d(db);
                        d.drop_function(stmtDrop);
                    }
                }else{
                    DB database(stmtDrop->name);
                    database.drop_function(stmtDrop);
                }
                
                    
            }
            
            break;
            }
            
        }
        else
        {
            othersql(&db, query);
        }
    }

    return 1;
}