#include <list>
#include <vector>
#include<iostream>
#include<string>
#include<map>
#include "table.h"
class DB
{
private:
    
    
    std::map<std::string, table*> tables;

public:
    std::string create_table();

    std::string drop_table();

    std::string select();

    std::string insert();
    
    std::string update();

    std::string del();

};