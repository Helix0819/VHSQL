#include <list>
#include <vector>
#include<iostream>
#include<string>
#include<map>
#include "table.h"
#include "DDL.h"
#include "DML.h"
#include "SQLParser.h"
// contains printing utilities
#include "util/sqlhelper.h"

using column = std::pair<std::string,int>;

class DB
{
private:
    
    
    std::map<std::string, table*> tables;

public:
    std::string create_table(const hsql::CreateStatement* stmt);

    std::string drop_table();

    std::string select();

    std::string insert();
    
    std::string update();

    std::string del();

};

