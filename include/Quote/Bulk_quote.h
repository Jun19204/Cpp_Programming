#pragma once

#include "Quote/Disc_quote.h"
#include "Quote/Quote.h"


class Bulk_quote : public Disc_quote { // 파생 클래스
public:
  Bulk_quote() = default;
  Bulk_quote(
      const std::string &book, 
      double price, 
      std::size_t qty, 
      double disc
      )
    : Disc_quote(book, price, qty, disc)
  { }
  double net_price(std::size_t) const override;
  void debug(std::ostream &os) const override
  { 
    Quote::debug(os); 
    os << quantitiy_ << " " << discount_;
  }
};


inline
double Bulk_quote::net_price(std::size_t cnt) const
{
  if (cnt >= quantitiy_)
    return static_cast<double>(cnt) * (1 - discount_) * price_;
  else
    return static_cast<double>(cnt) * price_;
}


