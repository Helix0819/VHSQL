#include <stdlib.h>
#include <string>
#include<iostream>

// include the sql parser
#include "./include/SQLParser.h"

// contains printing utilities
#include "./include/util/sqlhelper.h"

int main()
{
    std::string testsql_01 = "select * from foo where a = 1;";

    std::string testsql_02 = "select a,b from student where name = jack;";

    std::string test3 = "INSERT INTO students VALUES ('Max', 1112233, 'Musterhausen', 2.3)";

    
    hsql::SQLParserResult result; //存放我们解析的结果
    hsql::SQLParser::parse(test3, &result);//parser()是执行解析的方法,在解析结束后我们结果存在result里


    //下面用循环是因为parser支持多个sql同时解析，所以可能会有多个解析结果在result中 所以要遍历
    for (auto i = 0u; i < result.size(); ++i)
    {
        auto stmt = (const hsql::SQLStatement*) result.getStatement(i);
        //result.getStatement(i)是解析的结果 我们要把它强制类型转换成(const SQLStatement*)才能知道它解析的是什么type的语句
        //或者当你知道他要被解析的type是select 你可以：
        //auto stmt = (const SelectStatement*) result.getStatement(i);
        //如果你不知道 你可以通过stmt->type()来查看，可能结果有：
        /*
        kStmtSelect,
        kStmtImport,
        kStmtInsert,
        kStmtUpdate,
        kStmtDelete,
        kStmtCreate,
        kStmtDrop,
        kStmtPrepare,
        kStmtExecute,
        kStmtExport,
        kStmtRename,
        kStmtAlter,
        kStmtShow,
        kStmtTransaction*/
        //他们是枚举类型

        auto stmt = (const hsql::SelectStatement*) result.getStatement(i);

        stmt->fromTable->name;//是select 语句中被选的表名 类型是char*

        stmt->whereClause->opType;//是where子句中的op，类型是枚举类型enum,可能的结果有
        /*
        kOpNone,
        kOpBetween,
        kOpCase,
        kOpCaseListElement,  
        kOpPlus,
        kOpMinus,
        kOpAsterisk,
        kOpSlash,
        kOpPercentage,
        kOpCaret,
        kOpEquals,
        kOpNotEquals,
        kOpLess,
        kOpLessEq,
        kOpGreater,
        kOpGreaterEq,
        kOpLike,
        kOpNotLike,
        kOpILike,
        kOpAnd,
        kOpOr,
        kOpIn,
        kOpConcat,
        kOpNot,
        kOpUnaryMinus,
        kOpIsNull,
        kOpExists*/

        stmt->whereClause->expr->name;//结果是a 即where子句中的列名

        stmt->whereClause->expr2->ival;//结果是1 即where 子句中的列值 ival类型为int 但这个情况比较复杂
        //stmt->whereClause->expr2->fval 这个是值为浮点数的情况 类型为double
        //stmt->whereClause->expr2->fval 这个是值为字符串的情况 类型为char* 
        //目前只了解这么多 因为我也只实现了这三个QAQ

        //最顶的是被select的列
        //SelectStatement中有这样一个成员std::vector<Expr*>* selectList;
        //如其名存储了被选中的列
        //它的运行逻辑大概是：
        for (hsql::Expr* expr : *stmt->selectList)
        {
            switch(expr->type)
            {
                case hsql::kExprStar:
                    //说明是* 所以后面的不检索也罢
                case hsql::kExprColumnRef:
                    expr->name;//是被选列的名字 类型是char*
                //当然还有特别多的case 但我不知道你有没有实现 比如order by之类的
                //相当复杂QAQ
            }
        }

    }



}