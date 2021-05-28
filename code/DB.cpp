#include "DB.h"
// include the sql parser
// #include "SQLParser.h"
// // contains printing utilities
// #include "util/sqlhelper.h"

#include "file.h"

void DB::createDB()
{
    // std::string db = stmt->tableName;
    std::string path = "data/" + dbName;
    if(access(path.c_str(),F_OK) == 0)
    {
        cout << "DataBase exists" << endl;
        // cout << "Database exists" << endl;
    }else{
        mkdir(path.c_str(),S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
        std::cout << "CREATE DATABASE SUCCESS" << std::endl;
    }
}


std::string DB::create_table(const hsql::CreateStatement* stmt)
{
    
    std::vector<hsql::ColumnDefinition*>::iterator it = stmt->columns->begin();
    
    std::vector<std::string> col_names;

    std::vector<std::string> col_types;

    std::string tablename = stmt->tableName;

    std::string dir = "data/" + dbName;

    

    if(table_exists(tablename) || table_exists(tablename))
    {
        std::cout<<"table exist!"<<std::endl;
        return "exist"; 
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
        case hsql::DataType::TEXT:
            col_types.push_back("string");
            continue;
        }
    }

    
    

    auto fs = File::create(dir +"/"+tablename+".idx");
    if (!fs.good())
        std::cout << "fs is bad" << std::endl;
    
    int counter = 0;
    
    for(auto it = col_names.begin();it!=col_names.end();++it)
    {
        if(counter == (col_names.size() - 1))
        {
            fs<<*it;
            counter = 0;
            break;
        }
        fs<<*it<<" ";
        counter++;
    }  

    fs <<std::endl;

    for(auto it = col_types.begin();it != col_types.end();++it)
    {
        if(counter == (col_types.size() - 1))
        {
            fs<<*it;
            counter = 0;
            break;
        }
        fs <<*it<<" ";
        counter++;
    }
    //fs <<std::endl;

    fs.close();

    fs = File::create(dir +"/"+tablename+".dat");
    if (!fs.good())
        std::cout << "fs is bad" << std::endl;    
    fs.close();

    std::cout<<"create table successfully"<<std::endl;
    return "success!\n";
    

}

bool DB::table_exists(std::string tablename)
{
    std::string pathIdx = "data/" + dbName + "/" + tablename + ".idx";
    std::string pathDat = "data/" + dbName + "/" + tablename + ".dat";

    if(!File::file_exists(pathIdx) || !File::file_exists(pathDat))
        return false;
    else
        return true;
}

std::string DB::drop_function(const hsql::DropStatement* stmt)
{
    if(stmt->type == hsql::kDropTable)
    {
        std::string tbname = stmt->name;
        
        std::string tbpath_idx = "data/" + dbName + "/" + tbname + ".idx"; 

        std::string tbpath_dat = "data/" + dbName + "/" + tbname + ".dat"; 

        if(table_exists(tbname)){
            File::rm_file(tbpath_idx);

            File::rm_file(tbpath_dat);
            
            std::cout<<"table deleted!"<<std::endl;
        }else{
            std::cout<<"table not found"<<std::endl;
        }
        

        return "delete table success";
    }else if(stmt->type == hsql::kDropDatabase)
    {
        std::string databasename = stmt->name;

        std::string path = "data/" + databasename;

        if(File::file_exists(path)){
            File::rm_dir(path);
            std::cout<<"database deleted!"<<std::endl;
        }else{
            std::cout<<"database not found!"<<std::endl;
        }
    
        return "database delete success";
    }
}