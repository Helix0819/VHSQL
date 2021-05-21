
#include<iostream>
#include<string>
#include <sys/stat.h>
#include <sys/types.h>
#include<vector>

#include "SQLParser.h"
// contains printing utilities
#include "util/sqlhelper.h"

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

    void del(const hsql::DeleteStatement* stmt);
    
    void insertWrite(std::vector<std::string> v);

    std::vector<std::string> load_one_row_from_data(std::string path);

    std::vector<std::string> load_data_from_file(std::string path,int lineNum);

    
};