
#include "table.h"
//#include "SQLParser.h"

#include "file.h"
#include <vector>

using namespace std;

//__________________________________WARNING________________________________
//insert只对插入的数据进行检查,然后调用的是insertWrite进行写入
void table::insert(const hsql::InsertStatement* stmt)
{   
    //想打开对应的索引表,并获取存放类型的容器,用0代表string,用1代表int
    std::ifstream fileIdx(database + '/' + tableName + ".idx", ios::app);
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

int table::get_table_colnums(std::string path)
{
    ifstream fileIdx(path.c_str(), ios::app);
    //创建一个索引类型容器
    std::string line;
    std::string type;
    int num = 0;
    getline(fileIdx, line);
    std::stringstream word(line);
    cout << word.str() << endl;
    cout << word.str().size() << endl;
    while (word.rdbuf() -> in_avail() != 0)
    {   
        
        num++;
        word >> type;
        word.clear();
        
    }
    std::cout<<num<<std::endl;
    return num;
}

void table::rewrite_file(std::vector<int> &rownums,std::string path)
{
    auto in = File::read(path.c_str());

    std::string val1;
    std::string stringputfile;

    int line = 1;

    int counter = 0;

    //std::cout<<rownums.size();

    while(getline(in,val1))
    {
        for(int i = 0;i<rownums.size();++i)
        {
            
            if(rownums[i] == line)
            {
                stringputfile += "";
                break;
            } 
            counter++;      
        }

        if(counter == rownums.size())
        {
            stringputfile += val1;
            stringputfile += "\n";
            counter = 0;
        }
        line++;
    }

    in.close();

    std::ofstream out;
    out.open(path.c_str());
    out.flush();
    out << stringputfile;
    out.close();
    return;
}

std::vector<std::string> table::load_data_from_file(std::string path, int lineNum)
{
    if (!File::file_exists(path))
        File::create_empty_file(path);

    auto is = File::read(path);

    std::string val;
    std::vector<std::string> row;

    int num = get_table_colnums(path);
    int line = 1;

    while (getline(is, val))
    {
        if (is.eof())
        {
            //std::cout << "file end" << std::endl;
            break;
        }

        if (lineNum == 1)
        {
            row = load_one_row_from_data(path);
            is.close();
            return row;
        }
        else if (line == lineNum - 1)
        {
            for (int i = 0; i < num; ++i)
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
    
    int num = get_table_colnums(path);

    for (int i = 0; i < num; ++i)
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

    char* tmpvalue = stmt->expr->expr2->name; //get the column value

    //我在这里修改过tableName-->tablename
    std::string idxpath = "../data/" + tablename + "/" + tablename + ".idx"; // fmt-file's path

    std::string datapath = "../data/" + tablename + "/" + tablename + ".dat"; // data-file's path

    int colnum = 0;

    std::vector<int> rownums;





    //check if table exist
    if (!File::file_exists(idxpath))
    {
        std::cout << "table doesn't exist!\n";
        return;
    }

    if(tmpvalue != nullptr)
    {
        std::string columnvalue = tmpvalue;

        std::vector<std::string> tmp;

        tmp = load_one_row_from_data(idxpath);

        int num = get_table_colnums(idxpath);

        for(size_t i = 0; i < num;++i)
        {
            if(tmp[i] == columname)
            {
                colnum = i;
                break;
            }
        }

        int j = 1;

        while(true)
        {
            tmp = load_data_from_file(datapath,j);

            if(tmp[colnum] == columnvalue)
            {
                rownums.push_back(j);
                break;
            }

            j++;
        }

        rewrite_file(rownums,datapath);

    }else
    {
        int ivalue = stmt->expr->expr2->ival;

        auto type = stmt->expr->opType;

        std::string columnvalue = std::to_string(ivalue);

        std::vector<std::string> tmp;

        std::string svalue;

        int num = get_table_colnums(idxpath);

        std::stringstream str2digit;

        int j = 1,k=0;

        switch(type)
        {
            case hsql::kOpEquals:
                tmp = load_one_row_from_data(idxpath);
                for(size_t i = 0; i < num;++i)
                {
                    if(tmp[i] == columname)
                    {
                        colnum = i;
                        break;
                    }
                }
                while(true)
                {
                    tmp = load_data_from_file(datapath,j);

                    if(tmp[colnum] == columnvalue)
                    {
                        rownums.push_back(j);
                        break;
                     }

                    j++;
                }
                rewrite_file(rownums,datapath);
                break;
            case hsql::kOpLess:
                //std::string columnvalue = std::to_string(ivalue);
                tmp = load_one_row_from_data(idxpath);
                int ivalue2;
                
                for(size_t i = 0; i < num;++i)
                {
                    if(tmp[i] == columname)
                    {
                        colnum = i;
                        break;
                    }
                }
                j  = 1;
                while(true)
                {
                    tmp = load_data_from_file(datapath,j);
                    if(tmp.size() == 0)
                        break;
                    
                    str2digit  << tmp[colnum];
                    str2digit >> ivalue2;

                    if(ivalue2 < ivalue)
                    {
                        rownums.push_back(j);
                        //break;
                     }
                    str2digit.clear();
                    j++;
                }
                rewrite_file(rownums,datapath);
                break;
            case hsql::kOpGreater:
                tmp = load_one_row_from_data(idxpath);
            
                for(size_t i = 0; i < num;++i)
                {
                    if(tmp[i] == columname)
                    {
                        colnum = i;
                        break;
                    }
                }
                j  = 1;
                while(true)
                {
                    tmp = load_data_from_file(datapath,j);
                    if(tmp.size() == 0)
                        break;
                    
                    str2digit  << tmp[colnum];
                    str2digit >> ivalue2;

                    if(ivalue2 > ivalue)
                    {
                        rownums.push_back(j);
                        //break;
                     }
                    str2digit.clear();
                    j++;
                }
                rewrite_file(rownums,datapath);
                break;

        }
    }
	return ;
   
}

void table::selectPosition(std::string colName, int *colNum)
{
    string line;
    string oneData;
    string jump;
    std::ifstream fileIdx(database + '/' + tableName + ".idx", ios::app);
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
void table::selectPair(int colNum, std::string *type)
{
    std::ifstream fileIdx(database + '/' + tableName + ".idx", ios::app);
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

    std::ifstream file(database + '/' + tableName + ".dat", ios::app);

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