#pragma once

#include "Query/QueryBase.h"
#include "Query/Query.h"
#include <string>

class BinaryQuery : public QueryBase {
protected:
  BinaryQuery(const Query& lhs, 
              const Query& rhs, 
              std::string op_sym)
    : lhs_(lhs)
    , rhs_(rhs)
    , op_sym_(op_sym) { }
  std::string rep() const override {
    return "(" + lhs_.rep() + " "
               + op_sym_ + " "
               + rhs_.rep() + ")";
  }
  Query lhs_, rhs_;
  std::string op_sym_;
};
