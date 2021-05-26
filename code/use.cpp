#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <string>
using namespace std;

void otherDB(string *DBName, string sqlWord)
{
    stringstream read(sqlWord);
    string word;
    string path;
    vector<string> other;

    while (read.rdbuf()->in_avail() != 0)
    {
        read >> word;
        other.push_back(word);
    }
    if (other.size() == 1&&*other.begin() == "exit"){exit(0);}
    if (other.size() == 2){}else{cout<<"I DO NOT UNDERSTAND"<<endl; return;}
    if (*other.begin() == "use"){}else{cout<<"I DO NOT UNDERSTAND"<<endl; return;}
    path = "../data/" + *(--other.end());
    if(access(path.c_str(),F_OK) == 0)
    {
        *DBName = *(--other.end());
    }else{
        cout << "DataBase not found" << endl;
        return;
    }
}

int main()
{
    string db;
    string sql = "exit";
    // otherDB(&db, sql);
    // cout << db << endl;
    int a;
    while(1){
        cin >> a;
        switch (a)
        {
        case 1:
            /* code */
            break;
        
        default:
            otherDB(&db, sql);
            break;
        }
    }
}