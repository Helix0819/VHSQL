
#include <stdlib.h>
#include <string>
#include<iostream>

// include the sql parser
#include "SQLParser.h"

// contains printing utilities
#include "util/sqlhelper.h"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    fprintf(stderr, "Usage: ./example \"SELECT * FROM test;\"\n");
    return -1;
  }
  std::string query = argv[1];

  // parse a given query
  hsql::SQLParserResult result;
  hsql::SQLParser::parse(query, &result);

  // check whether the parsing was successful

  if (result.isValid()) {
    printf("Parsed successfully!\n");
    printf("Number of statements: %lu\n", result.size());
    //std::string ret;
    for (auto i = 0u; i < result.size(); ++i) {
      // Print a statement summary.
      hsql::printStatementInfo(result.getStatement(i));
      auto stmt = (const hsql::CreateStatement*) result.getStatement(i);
      std::string x = stmt->tableName;
      std::cout<<x<<std::endl;
      std::vector<hsql::ColumnDefinition*>::iterator it = stmt->columns->begin();
      for(;it!=stmt->columns->end();++it)
      {
        
        std::cout<<(*it)->name<<std::endl;
        auto ret = (*it)->type;
        //(*it)->type.data_types;
        std::cout<<ret<<std::endl;
      }
    }
    return 0;
  } else {
    fprintf(stderr, "Given string is not a valid SQL query.\n");
    fprintf(stderr, "%s (L%d:%d)\n",
            result.errorMsg(),
            result.errorLine(),
            result.errorColumn());
    return -1;
  }
}
