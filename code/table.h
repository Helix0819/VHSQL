
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

    table(std::string _tname,std::string _dname)
    {
        this->tableName = _tname;
        this->database = _dname;
        // std::cout << "what you find is" << "./data/" << database << '/' << tableName << ".idx" << std::endl;

    };
    /*********************insert部分***********************/
    //insert最终调用部分
    void insert(const hsql::InsertStatement* stmt);
    //insert的写文件部分
    void insertWrite(std::vector<std::string> v);
    /******************************************************/
    //std::string select();

    int update();

    void del(const hsql::DeleteStatement* stmt);

    void rewrite_file(std::vector<int> &rownums,std::string path);

    int get_table_colnums(std::string path);

    
    
    

    std::vector<std::string> load_one_row_from_data(std::string path);

    std::vector<std::string> load_data_from_file(std::string path,int lineNum);

    /*******************************select部分********************************/
    //以下四个函数均以是相对稳健的函数,有参数则可直接调用
    //这个函数将用于查找指定列的位置下标
    void selectPosition(std::string colName, int *colNum);

    //这个函数将用于查找条件列的对应类型
    void selectPair(int colNum, std::string *type);

    //这个函数将用于返回一个bool容器,容器内每一个元素对应的是逐行表示行是否满足条件
    std::vector<bool> selectFilter(int colNum, std::ifstream &file, std::string op, std::string B, std::string type);

    //这个函数对应的是select语句执行,只需要调用此函数即可,不需要单独调用以上三个函数
    void select(const hsql::SelectStatement *stmt);
    /*************************************************************************/
    
};