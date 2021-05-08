#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string>
#include <unistd.h>
using namespace std;

class creatDb;
class creatTable;
class dropDb;
class dropTable;
class useDb;
class tableOp;

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
    ofstream tbFile();
    template <typename T>
    void tbType(T *type);
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

//打开表
class tableOp
{
protected:
    string rootPath = "../data/";
public:
    template <typename T>
    T readTable(string database, string table)
    {
        string path = rootPath + database + '/' + table + ".dat";
        T file;
        // file.open(path);
        if(access(path.c_str(),F_OK) == 0){
            file.open(path,ios::app);
        }else{
            cout << "Table not exists" << endl;
        }
        return file;
    }

    template <typename T>
    void closeTable(T& file){
        file.close();
    }
};

