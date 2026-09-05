#pragma once

#include "Query/BinaryQuery.h"
#include "Query/Query.h"
#include "Query/QueryBase.h"
#include "Query/QueryResult.h"
#include "Query/TextQuery.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query& lhs, const Query& rhs)
    : BinaryQuery(lhs, rhs, "&") { }
  [[nodiscard]]
  QueryResult eval(const TextQuery&) const override;
};

inline
Query operator&(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline
QueryResult
AndQuery::eval(const TextQuery& text) const {
  auto left = lhs_.eval(text);
  auto right = rhs_.eval(text);
  auto ret_lines = 
    std::make_shared<std::set<LineNo>>();
  std::set_intersection(left.begin(), left.end(), 
                        right.begin(), right.end(), 
                        std::inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.getFile());
}


