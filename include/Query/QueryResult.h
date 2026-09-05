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
  QueryResult(const std::string& sought,
              const std::shared_ptr<std::set<TextQuery::LineNo>> lines,
              const std::shared_ptr<std::vector<std::string>> file) 
    : sought_(sought)
     ,lines_(lines)
     ,file_(file) { }

private:
    std::string sought_;
    std::shared_ptr<std::set<TextQuery::LineNo>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};


