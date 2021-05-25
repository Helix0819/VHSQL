#include <list>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <string>
#include <map>
#include "table.h"
// #include "SQLParser.h"
// // contains printing utilities
// #include "util/sqlhelper.h"

using column = std::pair<std::string,int>;
using namespace std;

class DB
{
private:
    
    
    std::map<std::string, table*> tables;

public:

    //创建数据库
    std::string createDB(const hsql::CreateStatement* stmt);

    std::string create_table(const hsql::CreateStatement* stmt);

    std::string drop_table();

    std::string select();

    //std::string insert();
    
    std::string update();

    std::string del();

};

