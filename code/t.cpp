#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

//将用0表示string, 1表示int
//其中参数中第一个参数为将输入的插入数据SQL语句进行分析后,提出插入的数据生成并放入list容器中
void insertCheck(list<pair<string*, int*>> l, vector<int> l2)
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
    if(born == l2){
        cout << "数据插入合法" << endl;
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

int main()
{
    // var a;
    // // a = (var*)malloc(sizeof(var*));
    // //为了不出现空指针错误,要进行三步,给不用的指针赋空值,给用的分配内存,然后赋值
    // a.a = nullptr;
    // a.b = (string*)malloc(sizeof(string));
    // *a.b = "niaho";
    // if(a.a == nullptr)
    // {
    //     cout << *a.b;
    // }else{
    //     cout << *a.a;
    // }
    // type.push_back(0);
    // type.push_back(1);
    // for(list<int>::iterator it = type.begin(); it != type.end(); it++){
    //     cout << *it << "\t";
    // }
    // cout << endl;
    // list<pair<string*, int*>> ll;
    // string str = "Tom";
    // int a = 18;
    // pair<string*, int*> p(&str,&a);
    // ll.push_back(p);
    // string str2 = "Jer";
    // int a2 = 22;
    // pair<string*, int*> p2(&str2,&a2);
    // ll.push_back(p2);
    // list<pair<string*, int*>>::iterator it = ll.begin();
    // pair<string*, int*> p0;
    // p0 = *it;
    // cout << *p0.first;

    list<pair<string*, int*>> tes;
    insertGene("zhanghaoyu", &tes);
    insertGene("123", &tes);
    // list<pair<string*, int*>>::iterator it = tes.begin();
    // pair<string*, int*> p0;
    // p0 = *it;
    // cout << *p0.first << endl;
    // it++;
    // p0 = *it;
    // cout << *p0.second << endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    insertCheck(tes, v);
}