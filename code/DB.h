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
    
    std::string dbName;

    //std::map<std::string, table*> tables;

public:




    DB(std::string _dbname)
    {
        this->dbName = _dbname;
    }

    //创建数据库
    std::string createDB();

    std::string create_table(const hsql::CreateStatement* stmt);

    
    //std::string select();

    //std::string insert();

    bool table_exists(std::string tablename);

    std::string drop_table(const hsql::DropStatement* stmt);
    
    std::string update();

    std::string del();

};

