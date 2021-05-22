
#include "table.h"
//#include "SQLParser.h"
#include "DDL.h"

#include "file.h"
#include<vector>

using namespace std;



void table::insert(vector<string> insertdata)
{
    string s;
    char c;
    vector<string>::iterator it = insertdata.begin();
    string::iterator is;
    
    vector<int> vg;

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


    for(int i =0;i<column_types.size();++i)
    {
        if(column_types[i].second != vg[i])
        {
            cout<<"非法"<<endl;
            return ;
    
        }
    }

    cout<<"合法"<<endl;
    insertWrite(insertdata);
    
}

void table::insertWrite(vector<string> v)
{
    fstream file(database + '/' + tableName + ".dat", ios::app|ios::binary);
    string s;
    vector<string>::iterator it = v.begin();
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

std::vector<std::string> table::load_data_from_file(std::string path,int lineNum)
{
    if(!File::file_exists(path))
        File::create_empty_file(path);

    auto is = File::read(path);

    std::string val;
    std::vector<std::string> row;

    int line = 1;

    

    while(getline(is,val))
    {
        if(is.eof())
        {
            std::cout<<"file end"<<std::endl;
            break;
        }
        
        if(lineNum == 1)
        {
            row = load_one_row_from_data(path);
            return row;
        }else if(line == lineNum - 1)
        {
            for(int i=0;i < column_types.size();++i)
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
    // vector<string>::iterator it = row.begin();

    // for(;it != row.end();++it)
    // {
    //     std::cout<<*it<<" ";
    // }
}

std::vector<std::string> table::load_one_row_from_data(std::string path)
{
    if(!File::file_exists(path))
        File::create_empty_file(path);

    auto is = File::read(path);

    std::string val;
    std::vector<std::string> row;

    for(int i=0;i < column_types.size();++i)
    {
        is >> val;
        row.push_back(val);
    }

    is.close();
    return row;
}

void table::del(const hsql::DeleteStatement* stmt)
{
    std::string tablename = stmt->tableName; //get tablename

    std::string columname = stmt->expr->expr->name; //get the name of colmun gonna be deleted
    
    std::string columnvalue = stmt->expr->expr2->name; //get the column value 

    std::string fmtpath = "../data/" + tableName + "/"+tablename+".fmt"; // fmt-file's path

    std::string datapath = "../data/" + tablename + "/" + tablename + ".dat"; // data-file's path
    
    int colnum = 0;

    int rownum = 0;

    //check if table exist
    if(!File::file_exists(fmtpath))
    {
        std::cout<<"table doesn't exist!\n";
        return ;
    }

    //get column value
    std::vector<std::string> tmp;

    tmp = load_one_row_from_data(fmtpath);

    //find out the index of the column we gonna use
    for(size_t i = 0;i < column_types.size();++i)
    {
        if(tmp[i] == columname)
        {
            colnum = i;
            break;
        }

    }

    int i = 1;

    while(true)
    {
        tmp = load_data_from_file(datapath,i);

        if(tmp[colnum] == columnvalue)
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

    while(getline(in,val1))
    {
        if(line == rownum)
        {
            strinputfile += "\n"; 
        }else
        {
            strinputfile += val1;
            strinputfile += "\n";
        }
        line++;
    }
    
    in.close();

    ofstream out;
    out.open(datapath);
    out.flush();
    out<<strinputfile;
    out.close();





    //std::cout<<"delete row "<<rownum<<std::endl;





}