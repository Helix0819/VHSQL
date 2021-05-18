#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string>
#include <vector>
#include <list>
//#include "dbms.h"
#include <unistd.h>
#include "table.h"
#include "DDL.h"
using namespace std;
using column = std::pair<std::string,int>;

int main()
{
    vector<string> v;
    v.push_back("张皓宇");
    v.push_back("22");
    vector<string> v2;
    v2.push_back("23");
    v2.push_back("23");
    vector<string> v3;
    v3.push_back("白忠建");
    v3.push_back("40");
    vector<string> v4;
    v4.push_back("赵洋");
    v4.push_back("45");
//     vector<int> vs;
//     vs.push_back(0);
//     vs.push_back(1);

    vector<column> t;
    column name("name",0);
    column age("age",1);

    t.push_back(name);
    t.push_back(age);

    string dbPath;

    useDb u("people");
    dbPath = u.useFolder();
    cout << dbPath << endl;
    string s = "student";
    
    table student(s,dbPath,t);

    student.insert(v);
    student.insert(v2);
    student.insert(v3);
    student.insert(v4);
//     insertTable i(vs, s, dbPath, v);
//     insertTable i2(vs, s, dbPath, v2);
//     insertTable i3(vs, s, dbPath, v3);
//     insertTable i4(vs, s, dbPath, v4);

}