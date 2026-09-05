#pragma once

#include "Query/TextQuery.h"
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <ostream>

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);

public:
  QueryResult(std::string str,
              std::shared_ptr<std::set<TextQuery::LineNo>> lines,
              std::shared_ptr<std::vector<std::string>> file) 
    : sought_(str)
     ,lines_(lines)
     ,file_(file) { }

private:
    std::string sought_;
    std::shared_ptr<std::set<TextQuery::LineNo>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};


