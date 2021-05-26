#include <stdlib.h>
#include <string>
#include <iostream>

#include "SQLParser.h"

// contains printing utilities
#include "util/sqlhelper.h"
using namespace std;

int main()
{
    std::string query;

    getline(std::cin, query);

    cout << "sql is" << query << endl;

    hsql::SQLParserResult result;

    hsql::SQLParser::parse(query, &result);
    if(result.isValid()){
        cout << "something" << endl;
    }else{
        cout << "nothing" << endl;
    }
    auto stmt = (const hsql::SQLStatement *)result.getStatement(0);

    if (stmt->type() > 0 && stmt->type() <= 14)
    {

        switch (stmt->type())
        {
        case hsql::kStmtSelect:
            std::cout << "select" << std::endl;
            break;
            //类型转换....
        case hsql::kStmtInsert:
            std::cout << "insert" << std::endl;
            break;
            //类型转换....
        case hsql::kStmtCreate:
            std::cout << "create" << std::endl;
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
    }else{
        cout << "kongde woburenshi" << endl;
    }

    return 1;
}