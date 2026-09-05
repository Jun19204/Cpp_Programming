#pragma once

#include "Query/QueryBase.h"
#include "Query/TextQuery.h"
#include <memory>
#include <string>

class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
public:
  Query(const std::string&);
  QueryResult eval(const TextQuery &text) const {
    return query_->eval(text);
  }
  std::string rep() const { return query_->rep(); }
private:
  Query(std::shared_ptr<QueryBase> query) query_(query) { }
  std::shared_ptr<QueryBase> query_;
};
