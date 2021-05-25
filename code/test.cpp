
#include <iostream>
#include<string>
#include <sys/stat.h>
#include <sys/types.h>
#include<vector>
#include <sstream>
#include <fstream>
#include "SQLParser.h"
// contains printing utilities
#include "util/sqlhelper.h"

using namespace std;

int main()
{
    std::string testsql_01 = "create database student;";

    hsql::SQLParserResult result; //存放我们解析的结果
    hsql::SQLParser::parse(testsql_01, &result);

    // cout << result << endl;
    for (auto i = 0u; i < result.size(); ++i)
    {
        auto stmt = (const hsql::CreateStatement*) result.getStatement(i);
        cout << stmt->schema << endl;
    }
}