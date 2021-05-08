#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "DML.h"
using namespace std;

/******************************************************************************************/
//插入表数据
//将用0表示string, 1表示int
//其中参数中第一个参数为将输入的插入数据SQL语句进行分析后,提出插入的数据生成并放入list容器中
void insertTable::insertCheck(list<pair<string*, int*>> l)
{
    string *a;
    int *b;
    vector<int> born;
    pair<string*, int*> p0;
    for(list<pair<string*, int*>>::iterator it = l.begin(); it != l.end(); it++){
        p0 = *it;
        if(p0.first == nullptr){
            born.push_back(1);
            //说明存储的第一个属性是int类型
        }else{
            born.push_back(0);
            //说明存储的第一个属性是string类型
        }
    }
    if(born == this->dataFormat){
        cout << "数据插入合法" << endl;
        //将在这儿调用读写文件类中的写文件方法,将list容器写入表中
    }else{
        cout << "数据插入非法" << endl;
    }
}

//参数为传入的一个数据元(其中默认传进的是字符串), 第二个是进行插入操作的list容器
void insertGene(string dataUnit, list<pair<string*, int*>> *l)
{
    int *a;
    string *b;
    char c;
    pair<string*, int*> p;
    string::iterator it = dataUnit.begin();
    for(it;it != dataUnit.end();it++){
        c = *it;
        if(isdigit(c)){
            continue;
        }else{
            break;
        }
    }
    if(it == dataUnit.end()){
        b = nullptr;
        a = (int*)malloc(sizeof(int));
        *a = atoi(dataUnit.c_str());
        p.first = b;
        p.second = a;
    }else{
        a = nullptr;
        b = (string*)malloc(sizeof(string));
        *b = dataUnit;
        p.first = b;
        p.second = a;
    }
    l->push_back(p);//maybe wrong here
}

/******************************************************************************************/