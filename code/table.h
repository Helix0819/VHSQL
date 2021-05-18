
#include<iostream>
#include<string>
#include <sys/stat.h>
#include <sys/types.h>
#include<vector>

using column = std::pair<std::string,int>;

class table
{
private:
    
    
    
    std::vector<column> column_types; //column type and column name

    //std::vector<string> column; //column data
    

    std::string tableName;
    
    std::string database;

public:

    //using column = std::pair<std::string,int>;

    table(std::string _tname,std::string _dname,std::vector<column> _column_type)
    {
        this->tableName = _tname;
        this->database = _dname;
        this->column_types = _column_type;

    };

    void insert(std::vector<std::string> insertData);

    //std::string select();

    int update();
    
    void insertWrite(std::vector<std::string> v);

    
};