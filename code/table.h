
#include<iostream>
#include<string>
#include <sys/stat.h>
#include <sys/types.h>
#include<vector>
#include <sstream>

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

    //供select使用的私有成员


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

    /*******************************select部分********************************/
    //以下四个函数均以是相对稳健的函数,有参数则可直接调用
    //这个函数将用于查找指定列的位置下标
    void selectPosition(string fileName, string colName, int *colNum);

    //这个函数将用于查找条件列的对应类型
    void selectPair(int colNum, string fileName, string *type);

    //这个函数将用于返回一个bool容器,容器内每一个元素对应的是逐行表示行是否满足条件
    vector<bool> selectFilter(int colNum, ifstream &file, string op, string B, string type);

    //这个函数对应的是select语句执行,只需要调用此函数即可,不需要单独调用以上三个函数
    void select(const hsql::SelectStatement *stmt);
    /*************************************************************************/
    
};