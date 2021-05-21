#include "DB.h"
// include the sql parser
// #include "SQLParser.h"
// // contains printing utilities
// #include "util/sqlhelper.h"

#include "file.h"


std::string DB::create_table(const hsql::CreateStatement* stmt)
{
    
    std::vector<hsql::ColumnDefinition*>::iterator it = stmt->columns->begin();
    std::vector<std::string> col_names;
    std::vector<int> col_types;
    std::string tablename = stmt->tableName;

    for(;it!=stmt->columns->end();++it)
    {
        col_names.push_back((*it)->name);
        auto type = (*it)->type.data_type;
        switch (type)
        {
        case hsql::DataType::UNKNOWN:
            col_types.push_back(-1);
            continue;
        case hsql::DataType::INT:
            col_types.push_back(1);
            continue;
        case hsql::DataType::LONG:
            col_types.push_back(2);
            continue;
        case hsql::DataType::FLOAT:
            col_types.push_back(3);
            continue;
        case hsql::DataType::DOUBLE:
            col_types.push_back(4);
            continue;
        case hsql::DataType::TEXT:
            col_types.push_back(5);
            continue;
        }
    }

    std::string dir = "../data/" + tablename;
    if(File::create_dir(dir))
    {
        auto fs = File::create("../data/" + tablename +"/"+tablename+".fmt");
        if (!fs.good())
            std::cout << "fs is bad" << std::endl;\
        
        for(auto it = col_names.begin();it!=col_names.end();++it)
        {
            fs<<*it<<" ";
        }  

        fs <<std::endl;

        for(auto it = col_types.begin();it != col_types.end();++it)
        {
            fs <<*it<<" ";
        }
        fs <<std::endl;

        fs.close();

        

        std::cout<<"create table successfully";
    }

}