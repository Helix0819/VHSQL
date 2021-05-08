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
public:
    insertTable(vector<int> exam){
        this->dataFormat = exam;
    }
    void insertCheck(list<pair<string*, int*>> l);
    void insertGene(string dataUnit, list<pair<string*, int*>> *l);
};