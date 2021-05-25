
#include "table.h"
//#include "SQLParser.h"
#include "DDL.h"

#include "file.h"
#include <vector>

using namespace std;

void table::insert(std::vector<std::string> insertdata)
{
    std::string s;
    char c;
    std::vector<std::string>::iterator it = insertdata.begin();
    std::string::iterator is;

    std::vector<int> vg;

    while (it != insertdata.end())
    {
        s = *it;
        for (is = s.begin(); is != s.end(); is++)
        {
            c = *is;
            if (isdigit(c) != 0)
            {
                //c是数字
                // cout << isdigit(c) << endl;
                continue;
            }
            else
            {
                //字符
                // cout << isdigit(c) << endl;
                break;
            }
        }
        if (is == s.end())
        {
            //c是数字
            vg.push_back(1);
        }
        else
        {
            //是字符
            vg.push_back(0);
        }
        it++;
    }

    for (int i = 0; i < column_types.size(); ++i)
    {
        if (column_types[i].second != vg[i])
        {
            cout << "非法" << endl;
            return;
        }
    }

    cout << "合法" << endl;
    insertWrite(insertdata);
}

void table::insertWrite(std::vector<std::string> v)
{
    fstream file(database + '/' + tableName + ".dat", ios::app | ios::binary);
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

std::vector<std::string> table::load_data_from_file(std::string path, int lineNum)
{
    if (!File::file_exists(path))
        File::create_empty_file(path);

    auto is = File::read(path);

    std::string val;
    std::vector<std::string> row;

    int line = 1;

    while (getline(is, val))
    {
        if (is.eof())
        {
            std::cout << "file end" << std::endl;
            break;
        }

        if (lineNum == 1)
        {
            row = load_one_row_from_data(path);
            return row;
        }
        else if (line == lineNum - 1)
        {
            for (int i = 0; i < column_types.size(); ++i)
            {
                is >> val;
                row.push_back(val);
            }
        }
        line++;
    }

    is.close();
    //is.eof();

    return row;
    // std::vector<std::string>::iterator it = row.begin();

    // for(;it != row.end();++it)
    // {
    //     std::cout<<*it<<" ";
    // }
}

std::vector<std::string> table::load_one_row_from_data(std::string path)
{
    if (!File::file_exists(path))
        File::create_empty_file(path);

    auto is = File::read(path);

    std::string val;
    std::vector<std::string> row;

    for (int i = 0; i < column_types.size(); ++i)
    {
        is >> val;
        row.push_back(val);
    }

    is.close();
    return row;
}

void table::del(const hsql::DeleteStatement *stmt)
{
    std::string tablename = stmt->tableName; //get tablename

    std::string columname = stmt->expr->expr->name; //get the name of colmun gonna be deleted

    std::string columnvalue = stmt->expr->expr2->name; //get the column value

    //我在这里修改过tableName-->tablename
    std::string fmtpath = "../data/" + tablename + "/" + tablename + ".fmt"; // fmt-file's path

    std::string datapath = "../data/" + tablename + "/" + tablename + ".dat"; // data-file's path

    int colnum = 0;

    int rownum = 0;

    //check if table exist
    if (!File::file_exists(fmtpath))
    {
        std::cout << "table doesn't exist!\n";
        return;
    }

    //get column value
    std::vector<std::string> tmp;

    tmp = load_one_row_from_data(fmtpath);

    //find out the index of the column we gonna use
    for (size_t i = 0; i < column_types.size(); ++i)
    {
        if (tmp[i] == columname)
        {
            colnum = i;
            break;
        }
    }

    int i = 1;

    while (true)
    {
        tmp = load_data_from_file(datapath, i);

        if (tmp[colnum] == columnvalue)
        {
            rownum = i;
            break;
        }

        i++;
    }

    auto in = File::read(datapath);

    int line = 1;

    std::string val1; //a tmp variable;
    std::string strinputfile;

    while (getline(in, val1))
    {
        if (line == rownum)
        {
            strinputfile += "\n";
        }
        else
        {
            strinputfile += val1;
            strinputfile += "\n";
        }
        line++;
    }

    in.close();

    std::ofstream out;
    out.open(datapath);
    out.flush();
    out << strinputfile;
    out.close();

    //std::cout<<"delete row "<<rownum<<std::endl;
}

// void table::selectValue(const hsql::SelectStatement *stmt){
//     //这里我尝试获取表名
//     std::string fileName = (char*)stmt->fromTable->name;
//     //我将会拿到对应的表名以及表结构的路径
//     std::string fmtpath = "../data/" + fileName + "/" + fileName + ".fmt";
//     std::string datpath = "../data/" + fileName + "/" + fileName + ".dat";
//     //这里我尝试获得where子句
//     //先拿到A
//     std::string A = (char*)stmt->whereClause->expr->name;
//     //再拿到op
//     std::string op;
//     hsql::OperatorType o = stmt->whereClause->opType;
//     switch (o)
//     {
//     case hsql::OperatorType::kOpEquals:
//         op = "=";
//         break;
//     case hsql::OperatorType::kOpLess:
//         op = "<";
//         break;
//     case hsql::OperatorType::kOpGreater:
//         op = ">";
//         break;
//     default:
//         break;
//     }
//     //再拿B
//     //首先我要先由A知道B的类型
//     // selectPosition(fileName, colName, int *colNum);
//     // if(stmt->whereClause->expr2->ival == nullptr)
//     // enum op = stmt->whereClause->opType;
// }


void table::selectPosition(std::string fileName, std::string colName, int *colNum)
{
    std::string line;
    std::string oneData;
    std::string jump;
    std::ifstream fileIdx(fileName + ".fmt", ios::app);
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
void table::selectPair(int colNum, std::string fileName, std::string *type)
{
    std::ifstream fileIdx(fileName + ".fmt", ios::app);
    std::string line;
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
std::vector<bool> table::selectFilter(int colNum, std::ifstream &file, std::string op, std::string B, std::string type)
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

void table::select(const hsql::SelectStatement *stmt)
{
    //接下来是修改部分,由于我调用了select状态,所以,我将会让fileName,colName和cond都从中间提取
    std::string fn = (char*)stmt->fromTable->name;
    //我将会拿到对应的表名以及表结构的路径的基础路径(就是不加文件后缀名如.dat的路径)
    std::string fileName = "../data/" + fn + "/" + fn;
    //接下来获取的是colName
    std::string colName = (char*)stmt->selectList->at(0)->getName();
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
    std::ifstream file(fileName + ".dat", ios::app);
    //创造用于解析cond的变量三个
    std::string A;
    std::string op;
    std::string B;
    //定义索引行的类型
    std::string type;
    //先创造一个用于判断的布尔容器
    std::vector<bool> judge;
    /**************尝试在这儿用新的方法获取到A op B************************/
    if(stmt->whereClause->expr->name != nullptr){
        //拿到A
        A = (char*)stmt->whereClause->expr->name;
        //找到条件列的位置
        selectPosition(fileName, A, &condColNum);
        //找到条件列类型,放到type中
        selectPair(condColNum, fileName, &type);
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
        selectPosition(fileName, colName, &colNum);
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