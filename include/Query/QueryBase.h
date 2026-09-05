#pragma once

#include "Query/Query.h"
#include <string>

// 4가지 조회 종류의 공통 인터페이스(추상 클래스)
class QueryBase {
  friend class Query;
protected:
  using line_no = TextQuery::line_no;
  virtual ~QueryBase() = default;
private:
  // eval에서는 이 Query와 일치하는 QueryResult를 반환한다.
  virtual QueryResult eval(const TextQuery&) const = 0;
  // rep는 조회 내용을 표현한 string이다.
  virtual std::string rep() const = 0;
};
