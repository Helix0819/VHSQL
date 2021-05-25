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

int main()
{
//##############################
//insert test
    
    // vector<string> v;
    // v.push_back("张皓宇");
    // v.push_back("22");
    // vector<string> v2;
    // v2.push_back("23");
    // v2.push_back("23");
    // vector<string> v3;
    // v3.push_back("白忠建");
    // v3.push_back("40");
    // vector<string> v4;
    // v4.push_back("赵洋");
    // v4.push_back("45");
// //     vector<int> vs;
// //     vs.push_back(0);
// //     vs.push_back(1);

    // vector<column> t;
    // column name("name",0);
    // column age("age",1);

    // t.push_back(name);
    // t.push_back(age);

    // string dbPath;

    // useDb u("student");
    // dbPath = u.useFolder();
    // cout << dbPath << endl;
    // string s = "student";
    
    // std::string datafile =dbPath+"/student.dat";
    // table student(s,dbPath,t);

    // student.insert(v);
    // student.insert(v2);
    // student.insert(v3);
    // student.insert(v4);
//insert test end
//####################################


//####################################
//delete test

    // std::string delsql = "delete from student where name = eilliot;";
    // hsql::SQLParserResult result;
    // hsql::SQLParser::parse(delsql,&result);
    // auto stmt = (const hsql::DeleteStatement*) result.getStatement(0);
    // student.del(stmt);
//delete test end
//####################################

//####################################
//create table test
    // std::string sql = "create table helix (id TEXT,age INT);";
    // hsql::SQLParserResult result;
    // hsql::SQLParser::parse(sql,&result);
    // auto stmt = (const hsql::CreateStatement*) result.getStatement(0);

    // DB d1;
    // d1.create_table(stmt);
//create table test end
//#####################################

//#####################################
//drop table test
    std::string sql = "drop table test;";
    hsql::SQLParserResult result;
    hsql::SQLParser::parse(sql,&result);
    auto stmt = (const hsql::DropStatement*) result.getStatement(0);
    
    DB test("test");
    test.drop_table(stmt);
}