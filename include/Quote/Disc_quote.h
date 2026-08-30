#pragma once

#include "Quote/Quote.h"


// 할인율과 수량을 담는 추상 기초 클래스
class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(
      const std::string &book,
      double price,
      std::size_t qty,
      double disc
      )
    : Quote(book, price), quantitiy{qty}, discount{disc}
  { }
  double net_price(std::size_t) const = 0;
protected:
  std::size_t quantitiy = 0;
  double discount = 0.0;
};


