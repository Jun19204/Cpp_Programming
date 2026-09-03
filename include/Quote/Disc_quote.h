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
    : Quote(book, price), quantitiy_{qty}, discount_{disc}
  { }
  [[nodiscard]]
  double net_price(std::size_t cnt) const = 0;

protected:
  std::size_t quantitiy_ = 0;
  double discount_ = 0.0;
};


