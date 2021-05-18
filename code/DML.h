#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//插入表数据
class insertTable
{
protected:
    vector<int> dataFormat;
    string tableName;
    string database;
    vector<string> insertData;
    //vector<string> colnames;
public:
    insertTable(vector<int> exam, string name, string globalPath, vector<string> con){
        this->dataFormat = exam;
        this->tableName = name;
        this->database = globalPath;
        this->insertData = con;
        this->insertGene();
    }
    void insertGene();
    void insertWrite(vector<string> v);
};