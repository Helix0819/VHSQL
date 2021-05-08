#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string>
#include "DDL.h"
#include <unistd.h>
using namespace std;

int main()
{
    // string str;
    // creatDb c("people");
    // c.dbFolder();
    // // dropDb d("test");
    // // d.dropFolder();
    // // dropDb d2("people");
    // // d2.dropFolder();
    // useDb u("people");
    // u.useFolder(&str);
    // creatTable c2("people","student");
    // c2.tbFile();
    // dropTable d("people","student");
    // d.dropFile();
    tableOp t;
    ifstream i;
    i = t.readTable<ifstream>("people", "student");
    char data[100];
    i >> data;
    cout << data + '\n' << endl;
    // cout << typeid(data)
    t.closeTable<ifstream>(i);
    // ofstream i2;
    // i2 = t.readTable<ofstream>("people", "student");
    // cin >> data;
    // i2 << data << endl;


}