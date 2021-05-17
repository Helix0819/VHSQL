#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "dbms.h"
using namespace std;

/******************************************************************************************/
//插入表数据
//将用0表示string, 1表示int
//用于检查
void insertTable::insertGene()
{
    string s;
    char c;
    vector<string>::iterator it = insertData.begin();
    string::iterator is;
    vector<int> vg;
    while (it != insertData.end())
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

    if (vg == this->dataFormat)
    {
        cout << "合法" << endl;
        insertWrite(insertData);
    }
    else
    {
        cout << "非法" << endl;
    }
}

//用于写文件
void insertTable::insertWrite(vector<string> v)
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
/******************************************************************************************/