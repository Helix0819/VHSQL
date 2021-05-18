
#include "table.h"
//#include "SQLParser.h"
#include "dbms.h"

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
    fstream file(table::database + '/' + tableName + ".dat", ios::app|ios::binary);
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