#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string>
#include <vector>
#include <list>
#include "dbms.h"
#include <unistd.h>

using namespace std;

int main()
{
    vector<string> v;
    v.push_back("张皓宇");
    v.push_back("22");
    vector<string> v2;
    v2.push_back("vv");
    v2.push_back("55");
    vector<string> v3;
    v3.push_back("sdf");
    v3.push_back("23");
    vector<string> v4;
    v4.push_back("dga");
    v4.push_back("56");
    vector<int> vs;
    vs.push_back(0);
    vs.push_back(1);

    string dbPath;

    useDb u("people");
    dbPath = u.useFolder();
    cout << dbPath << endl;
    string s = "student";
    insertTable i(vs, s, dbPath, v);
    insertTable i2(vs, s, dbPath, v2);
    insertTable i3(vs, s, dbPath, v3);
    insertTable i4(vs, s, dbPath, v4);
}