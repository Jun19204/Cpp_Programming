#pragma once

#include "Query/BinaryQuery.h"
#include "Query/Query.h"
#include "Query/QueryBase.h"
#include "Query/QueryResult.h"
#include "Query/TextQuery.h"
#include <memory>

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
