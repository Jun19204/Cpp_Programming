#pragma once

#include "Query/QueryBase.h"
#include "Query/Query.h"
#include "Query/TextQuery.h"
#include <memory>
#include <string>

class NotQuery : public QueryBase {
  friend Query operator~(const Query&);
  NotQuery(const Query& query) : query_(query) { }
  [[nodiscard]]
  std::string rep() const override { 
    return "~(" + query_.rep() + ")";
  }
  [[nodiscard]]
  QueryResult eval(const TextQuery&) const;
  Query query_;
};

inline
Query operator~(const Query& operand) {
  return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

