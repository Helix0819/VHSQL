#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <list>
//#include "dbms.h"
#include <unistd.h>

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
    }
    else
    {
        cout << "DataBase not found" << endl;
        return;
    }
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
                    std::cout << "select" << std::endl;
                    auto stmtSel = (const hsql::SelectStatement *)result.getStatement(0);
                    tb = stmtSel->fromTable->getName();
                    //检查表是否存在...

                    table t(tb, db);
                    t.select(stmtSel);
                }
            }

            break;
                //类型转换....
            case hsql::kStmtInsert:
            {
                //调用select
                if (db.empty())
                {
                    cout << "BEFORE YOU INSERT, ENTRY A DATABASE FIRST" << endl;
                }
                else
                {
                    std::cout << "insert" << std::endl;
                    auto stmtIns = (const hsql::InsertStatement *)result.getStatement(0);
                    tb = stmtIns->tableName;
                    //检查表是否存在...

                    table t(tb, db);
                    t.insert(stmtIns);
                }
            }

            break;
                //类型转换....
            case hsql::kStmtCreate:
            {
                std::cout << "create" << std::endl;
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
                    cout << stmtCre->tableName;
                }
                else
                {
                    //创建数据库
                    DB database(stmtCre->schema);
                    database.createDB();
                }
            }

            break;
                //类型转换....
            case hsql::kStmtDelete:
                std::cout << "delete" << std::endl;
                break;
                //类型转换....
            case hsql::kStmtDrop:
                std::cout << "drop" << std::endl;
                break;
                //类型转换....
            }
        }
        else
        {
            othersql(&db, query);
        }
    }

    return 1;
}