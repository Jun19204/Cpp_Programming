#pragma once

#include "Quote/Quote.h"


class Bulk_quote : public Quote { // 파생 클래스
public:
  Bulk_quote() = default;
  Bulk_quote(
      const std::string &book, 
      double p, 
      std::size_t qty, 
      double disc
      )
    : Quote(book, p), min_qty(qty), discount(disc)
  { }
  double net_price(std::size_t) const override;
  void debug(std::ostream &os) const override
  { Quote::debug(os); os << min_qty << " " << discount << "\n"; }
private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};


inline
double Bulk_quote::net_price(std::size_t cnt) const
{
  if (cnt >= min_qty)
    return static_cast<double>(cnt) * (1 - discount) * price;
  else
    return static_cast<double>(cnt) * price;
}


