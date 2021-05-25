#include <list>
#include <vector>
#include<iostream>
#include<string>
#include<map>
#include "table.h"
#include "DDL.h"
#include "DML.h"
// #include "SQLParser.h"
// // contains printing utilities
// #include "util/sqlhelper.h"

using column = std::pair<std::string,int>;

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
    std::string create_table(const hsql::CreateStatement* stmt);

    
    //std::string select();

    //std::string insert();

    bool table_exists(std::string tablename);

    std::string drop_table(const hsql::DropStatement* stmt);
    
    std::string update();

    std::string del();

};

