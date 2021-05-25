#include "DB.h"
// include the sql parser
// #include "SQLParser.h"
// // contains printing utilities
// #include "util/sqlhelper.h"

#include "file.h"

std::string DB::createDB()
{
    // std::string db = stmt->tableName;
    std::string path = "../data/" + dbName;
    if(access(path.c_str(),F_OK) == 0)
    {
        cout << "DataBase has already exists" << endl;
        // cout << "Database exists" << endl;
    }else{
        mkdir(path.c_str(),S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
    }
}


std::string DB::create_table(const hsql::CreateStatement* stmt)
{
    
    std::vector<hsql::ColumnDefinition*>::iterator it = stmt->columns->begin();
    
    std::vector<std::string> col_names;

    std::vector<std::string> col_types;

    std::string tablename = stmt->tableName;

    std::string dir = "../data/" + tablename;

    if(File::dir_exists(dir))
    {
        std::cout<<"table already exists!"<<std::endl;
        return "exists";
    }    

    

    for(;it!=stmt->columns->end();++it)
    {
        col_names.push_back((*it)->name);
        auto type = (*it)->type.data_type;
        switch (type)
        {
        case hsql::DataType::UNKNOWN:
            col_types.push_back("unknown");
            continue;
        case hsql::DataType::INT:
            col_types.push_back("int");
            continue;
        case hsql::DataType::LONG:
            col_types.push_back("long");
            continue;
        case hsql::DataType::FLOAT:
            col_types.push_back("float");
            continue;
        case hsql::DataType::DOUBLE:
            col_types.push_back("double");
            continue;
        case hsql::DataType::TEXT:
            col_types.push_back("text");
            continue;
        }
    }

    
    
    if(File::create_dir(dir))
    {
        auto fs = File::create("../data/" + tablename +"/"+tablename+".idx");
        if (!fs.good())
            std::cout << "fs is bad" << std::endl;
        
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

        

        std::cout<<"create table successfully"<<std::endl;
        return "success!\n";
    }

}

bool table_exists(std::string tablename)
{
    std::string path = "../data/" + tablename + "/" + tablename + ".idx";

    if(!File::file_exists(path))
        return false;
    else
        return true;
}

std::string DB::drop_table(const hsql::DropStatement* stmt)
{
    if(stmt->type == hsql::kDropTable)
    {
        std::string tbname = stmt->name;
        
        std::string tbpath_idx = "../data/" + tbname + "/" + tbname + ".idx"; 

        std::string tbpath_dat = "../data/" + tbname + "/" + tbname + ".dat"; 

        remove(tbpath_idx.c_str());

        remove(tbpath_dat.c_str());

        std::cout<<"table deleted!"<<std::endl;

        return "delete table success";
    }
}