#pragma once

#include "Query/Query.h"
#include "Query/QueryBase.h"
#include "Query/QueryResult.h"
#include <string>

class WordQuery : public QueryBase {
  friend class Query;
  WordQuery(const std::string& str) : query_word_(str) { }
  [[nodiscard]]
  QueryResult eval(const TextQuery& text) const override {
    return text.query(query_word_);
  }
  [[nodiscard]]
  std::string rep() const override { return query_word_; }
  std::string query_word_;
};
