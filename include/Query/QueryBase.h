#pragma once

#include "Query/TextQuery.h"
#include <string>


// 4가지 조회 종류의 공통 인터페이스(추상 클래스)
class QueryBase {
  friend class Query;
protected:
  using LineNo = TextQuery::LineNo;
  virtual ~QueryBase() = default;
private:
  // eval에서는 이 Query와 일치하는 QueryResult를 반환한다.
  [[nodiscard]]
  virtual QueryResult eval(const TextQuery&) const = 0;
  // rep는 조회 내용을 표현한 string이다.
  [[nodiscard]]
  virtual std::string rep() const = 0;
};
