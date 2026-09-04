#pragma once

#include "Quote/Quote.h"
#include <memory>
#include <ostream>
#include <set>

class Basket {
public:
  /* 합성버전 기본 생성자와 복사 제어 멤버를 사용 */
  void addItem(const Quote& sale) {
    items_.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void addItem(Quote&& sale) {
    items_.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }
  double totalReceipt(std::ostream&) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs
                    , const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>
              , decltype(compare)*> items_{compare};
};

