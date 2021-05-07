#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//创建数据库
class creatDb
{
protected:
    string name;
    string rootPath = "../data/";
public:
    creatDb(string dbName)
    {
        this->name = dbName;
    }
    void dbFolder();
};

//创建表
class creatTable
{
protected:
    string name;
    string rootPath = "../data/";
    string database;
public:
    creatTable(string dbName, string tbName)
    {
        this->name = tbName;
        this->database = dbName;
    }
    void tbfile();
};

//删除数据库
class dropDb
{
protected:
    string dropName;
    string rootPath = "../data/";
public:
    dropDb(string dbDropName)
    {
        this->dropName = dbDropName;
    }
    void dropFolder();
};

//删除表
class dropTable
{
protected:
    string dropName;
    string rootPath = "../data/";
    string dropTableName;
public:
    dropTable(string dbDropName, string tbDropName)
    {
        this->dropName = dbDropName;
        this->dropTableName = tbDropName;
    }
    void dropFile();
};

//切换数据库
class useDb
{
protected:
    string useName;
    string rootPath = "../data/";
public:
    useDb(string dbUseName)
    {
        this->useName = dbUseName;
    }
    void useFolder(string *str);
};
