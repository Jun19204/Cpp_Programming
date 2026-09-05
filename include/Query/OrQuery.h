#pragma once

#include "Query/BinaryQuery.h"
#include "Query/Query.h"
#include "Query/QueryBase.h"
#include "Query/QueryResult.h"
#include "Query/TextQuery.h"
#include <memory>
#include <set>

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query& lhs, const Query& rhs)
    : BinaryQuery(lhs, rhs, "|") { }
  [[nodiscard]]
  QueryResult eval(const TextQuery&) const override;
};

inline
Query operator|(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

inline
QueryResult
OrQuery::eval(const TextQuery& text) const {
  auto right = rhs_.eval(text);
  auto left = lhs_.eval(text);
  auto ret_lines = 
    std::make_shared<std::set<LineNo>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.getFile());
}
