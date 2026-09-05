#pragma once

#include "Query/QueryBase.h"
#include "Query/TextQuery.h"
#include "Query/QueryResult.h"
#include "Query/WordQuery.h"
#include <memory>
#include <ostream>
#include <string>

class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);
public:
  Query(const std::string&);
  [[nodiscard]]
  QueryResult eval(const TextQuery &text) const {
    return query_->eval(text);
  }
  [[nodiscard]]
  std::string rep() const { 
    return query_->rep(); 
  }
private:
  Query(std::shared_ptr<QueryBase> query) : query_(query) { }
  std::shared_ptr<QueryBase> query_;
};

inline
Query::Query(const std::string& str)
  : query_{new WordQuery(str)} { }

inline
std::ostream&
operator<<(std::ostream& ostrm, const Query& query) {
  return ostrm << query.rep();
}

