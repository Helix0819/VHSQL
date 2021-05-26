
#include <iostream>
#include<string>
#include <sys/stat.h>
#include <sys/types.h>
#include<vector>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include "./include/SQLParser.h"
// contains printing utilities
#include "./include/util/sqlhelper.h"

using namespace std;

void insert(const hsql::InsertStatement* stmt);
void insertWrite(std::vector<std::string> v);
void select(const hsql::SelectStatement *stmt);
std::vector<bool> selectFilter(int colNum, std::ifstream &file, std::string op, std::string B, std::string type);
void selectPair(int colNum, string *type);

void insert(const hsql::InsertStatement* stmt)
{   
    //想打开对应的索引表,并获取存放类型的容器,用0代表string,用1代表int
    ifstream fileIdx("test.idx", ios::app);
    //创建一个索引类型容器
    vector<int> idx;
    string line;
    string type;
    while (getline(fileIdx, line))
    {
    }
    std::stringstream word(line);
    // cout << word.str() << endl;
    while (word.rdbuf() -> in_avail() != 0)
    {
        word >> type;
        // cout << type << endl;
        if(type == "string"){
            idx.push_back(0);
        }else if(type == "int"){
            idx.push_back(1);
        }
        word.clear();
    }
    fileIdx.close();
    //得到了索引容器

    vector<hsql::Expr*> *v = stmt->values;
    vector<hsql::Expr*>::iterator it = v->begin();
    vector<int>::iterator itIdx =  idx.begin();
    // 需要存放的数据
    string str;
    vector<string> insertData;
    // std::vector<Expr*>::iterator it = stmt->values->begin();
    if(v->size() != idx.size()){
        cout << "非法插入" << endl;
        return;
    }
    //new way使用for循环遍历结果集
    for(hsql::Expr* expr : *stmt->values)
    {
        if(*itIdx == 0){
            // A STRING TYPE
            /*_________________WARNING__________________________*/
            if(expr->name == nullptr){
                cout << "非法插入" << endl;
                return;
            }else{
                str = expr->name;
                insertData.push_back(str);
            }
        }else if(*itIdx == 1){
            // A int TYPE
            /*_________________WARNING__________________________*/
            if(expr->ival == 0){
                cout << "非法插入" << endl;
                return;
            }else{
                str = to_string(expr->ival);
                insertData.push_back(str);
            }
        }
        itIdx++;
    }
    //检查完毕,开始插入
    insertWrite(insertData);
}
//__________________________________WARNING________________________________

void insertWrite(std::vector<std::string> v)
{
    fstream file("test.dat", ios::app | ios::binary);
    std::string s;
    std::vector<std::string>::iterator it = v.begin();
    while (it != v.end())
    {
        s = *it;
        if (it != --v.end())
        {
            file << s << '\t';
        }
        else
        {
            file << s;
        }
        it++;
    }
    file << endl;
    file.close();
}

void createDB(string dbName)
{
    // std::string db = stmt->tableName;
    std::string path = "../data/" + dbName;
    if(access(path.c_str(),F_OK) == 0)
    {
        cout << "DataBase has already exists" << endl;
        // cout << "Database exists" << endl;
    }else{
        mkdir(path.c_str(),S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
    }
}

//select测试

void selectPosition(string colName, int *colNum)
{
    string line;
    string oneData;
    string jump;
    ifstream fileIdx("test.idx", ios::app);
    getline(fileIdx, line);
    std::stringstream word(line);
    //找到索引列位置
    while (oneData != colName)
    {
        word >> oneData;
        ++(*colNum);
        if (jump == oneData)
        {
            cout << "未找到指定列" << endl;
            *colNum = 0;
            break;
        }
        else
        {
            jump = oneData;
        }
    }
    fileIdx.close();
}

//设置一个函数用于判别条件类型
void selectPair(int colNum, string *type)
{
    ifstream fileIdx("test.idx", ios::app);
    string line;

    while (getline(fileIdx, line))
    {
    }
    std::stringstream word(line);
    while (colNum != 0)
    {
        word >> *type;
        colNum--;
    }
    fileIdx.close();
}

//设置一个函数用于判断
std::vector<bool> selectFilter(int colNum, std::ifstream &file, std::string op, std::string B, std::string type)
{
    std::string line;
    std::string oneData;
    std::vector<bool> judge;
    std::vector<std::string> lineData;
    while (getline(file, line))
    {
        std::stringstream word(line);
        int temp = colNum;
        while (temp != 0)
        {
            word >> oneData;
            lineData.push_back(oneData);
            temp--;
        }
        //此时用于判断的值将会放在std::vector的末尾在一个循环中
        oneData = *(--lineData.end());
        //将会在std::vector容器的末尾进行判断是否满足条件
        if (type == "int")
        {
            char c = *op.begin();
            int a = atoi(oneData.c_str());
            int b = atoi(B.c_str());
            switch (c)
            {
            case '>':
                if (a > b)
                {
                    judge.push_back(true);
                }
                else
                {
                    judge.push_back(false);
                }
                break;
            case '<':
                if (a < b)
                {
                    judge.push_back(true);
                }
                else
                {
                    judge.push_back(false);
                }
                break;
            case '=':
                if (a == b)
                {
                    judge.push_back(true);
                }
                else
                {
                    judge.push_back(false);
                }
                break;
            default:
                break;
            }
        }
        else
        {
            if (oneData == B)
            {
                judge.push_back(true);
            }
            else
            {
                judge.push_back(false);
            }
        }
    }
    return judge;
}

void select(const hsql::SelectStatement *stmt)
{
    //接下来是修改部分,由于我调用了select状态,所以,我将会让fileName,colName和cond都从中间提取
    //在table进行实例化的时候我们已经拿到了对应表的基础路径
    //接下来获取的是colName
    std::string colName;
    if(stmt->selectList->at(0)->type != hsql::kExprStar){
        colName = (char*)stmt->selectList->at(0)->getName();
    }else{
        colName = "*";
    }
    //定义一个用于读取一行数据的std::string变量
    std::string line;
    //定义一个int用于指定指定列所在的位置
    int colNum = 0;
    int condColNum = 0;
    //定义一个用于获得单一字段的std::string
    std::string oneData;
    std::string jump;
    //定义一个用放一行数据的std::vector容器
    std::vector<std::string> lineData;
    //打开一个需要进行select的文件

    ifstream file("test.dat", ios::app);

    //创造用于解析cond的变量三个
    std::string A;
    std::string op;
    std::string B;
    //定义索引行的类型
    std::string type;
    //先创造一个用于判断的布尔容器
    std::vector<bool> judge;
    /**************尝试在这儿用新的方法获取到A op B************************/
    if(stmt->whereClause != nullptr){
        //拿到A
        A = (char*)stmt->whereClause->expr->name;
        //找到条件列的位置
        selectPosition(A, &condColNum);
        //找到条件列类型,放到type中
        selectPair(condColNum, &type);
        //拿到op
        hsql::OperatorType o = stmt->whereClause->opType;
        switch (o)
        {
        case hsql::OperatorType::kOpEquals:
            op = "=";
            break;
        case hsql::OperatorType::kOpLess:
            op = "<";
            break;
        case hsql::OperatorType::kOpGreater:
            op = ">";
            break;
        default:
            break;
        }
        //拿到B
        if(type == "int"){
            B = to_string(stmt->whereClause->expr2->ival);
        }else if(type == "std::string"){
            B = stmt->whereClause->expr2->name;
        }
        judge = selectFilter(condColNum, file, op, B, type);
    }
    /**************************end**************************************/

    std::vector<bool>::iterator itb = judge.begin();
    if (colName != "*")
    {
        //进行文件指针的重置
        file.clear();
        file.seekg(ios::beg);
        //先得到列的对应位号
        selectPosition(colName, &colNum);
        if (colNum == 0)
        {
            return;
        }
        //逐行读取,将读取的行数据放入一个std::vector中,使用迭代器遍历到相应的位置并取出,不加条件
        while (getline(file, line))
        {
            std::stringstream word(line);
            int temp = colNum;

            while (temp != 0)
            {
                word >> oneData;
                lineData.push_back(oneData);
                temp--;
            }
            //这是为存在或不存在有判断条件准备的
            if (judge.begin() != judge.end())
            {
                oneData = *(--lineData.end());
                if (*itb == true)
                {
                    cout << oneData << endl;
                }
                itb++;
            }
            else
            {
                cout << oneData << endl;
            }
        }
    }
    else
    {
        //进行文件指针的重置
        file.clear();
        file.seekg(ios::beg);
        while (getline(file, line))
        {
            if (judge.begin() != judge.end())
            {
                if (*itb == true)
                {
                    cout << line << endl;
                }
                itb++;
            }
            else
            {
                cout << line << endl;
            }
        }
    }
}

int main()
{
    std::string testsql_01 = "create database student;";
    std::string testsql_01_1 = "CREATE TABLE students (name TEXT, student_number INTEGER, city TEXT, grade DOUBLE);";
    std::string testsql_02 = "INSERT INTO students VALUES ('Venator', '002', '男')";
    std::string testsql_03 = "select * from test where id = 2";//error
    std::string testsql_04 = "select * from test";//error
    std::string testsql_05 = "select * from test where id > 2";//error
    std::string testsql_06 = "select name from test where id = 2";
    std::string testsql_07 = "select name from test where id > 2";
    std::string testsql_08 = "select name from test";

    hsql::SQLParserResult result; //存放我们解析的结果
    hsql::SQLParser::parse(testsql_01, &result);

    auto stmt = (const hsql::CreateStatement*) result.getStatement(0);
    cout << stmt->type << endl;
    // select(stmt);
    // if(stmt->schema == nullptr){
    //     cout << stmt->tableName;
    // }else{
    //     cout << stmt->schema;
    // }
    // cout << stmt->tableName;
    // select(stmt);
}

// int main()
// {
//     std::string query;

//     getline(std::cin,query);

//     hsql::SQLParserResult result;
    
//     hsql::SQLParser::parse(query,&result);

//     auto stmt = (const hsql::SQLStatement*) result.getStatement(0);

//     switch(stmt->type())
//     {
//         case hsql::kStmtSelect:
//         {
//             std::cout<<"select"<<std::endl;
//             auto stmtSel = (const hsql::SelectStatement*) result.getStatement(0);
//             select(stmtSelect);
//             // cout << (char*)stmtSelect->whereClause->expr->name << endl;
//         }
//             break;
//             //类型转换....
//         case hsql::kStmtInsert:
//             std::cout<<"insert"<<std::endl;
//             break;
//             //类型转换....
//         case hsql::kStmtCreate:
//             std::cout<<"create"<<std::endl;
//             break;
//             //类型转换....
//         case hsql::kStmtDelete:
//             std::cout<<"delete"<<std::endl;
//             break;
//             //类型转换....
//         case hsql::kStmtDrop:
//             std::cout<<"drop"<<std::endl;
//             break;
//             //类型转换....
//     }

//     return 1;

    
// }