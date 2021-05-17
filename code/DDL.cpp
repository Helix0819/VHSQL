#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string>
#include <unistd.h>
#include "DDL.h"
using namespace std;

//创建数据库
void creatDb::dbFolder()
{
    string path = rootPath + this->name;
    if(access(path.c_str(),F_OK) == 0)
    {
        cout << "Database exists" << endl;
    }else{
        mkdir(path.c_str(),S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
    }
}

// 创建表
ofstream creatTable::tbFile()
{
    ofstream file;
    string path = rootPath + database + '/' + this->name + ".dat";
    if(access(path.c_str(),F_OK) == 0){
        cout << "Table exits" << endl;
    }else{
        file.open(path);
        // file.close();
    }
    return file;
}

template <typename T>
void creatTable::tbType(T *type)
{
    // ofstream file = this->tbFile();

}

//删除数据库
void dropDb::dropFolder()
{
    string path = rootPath + this->dropName;
    if(access(path.c_str(),F_OK) == 0)
    {
        remove(path.c_str());
    }else{
        cout << "Database not exists" << endl;
    }
}

// //删除表
void dropTable::dropFile()
{
    string path = rootPath + this->dropName + '/' + dropTableName + ".dat";
    if(access(path.c_str(),F_OK) == 0)
    {
        remove(path.c_str());
    }else{
        cout << "Table not exists" << endl;
    }
}

// 切换数据库

string useDb::useFolder()
{
    return rootPath + this->useName;
}