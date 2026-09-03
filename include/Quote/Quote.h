#pragma once

#include <cstddef>
#include <ostream>
#include <string>


class Quote { // 기초 클래스
public:
  Quote() = default;
  Quote(
      const std::string &book, 
      double sales_price
      )
    : bookNo_(book), price_(sales_price)
  { }
  [[nodiscard]]
  std::string isbn() const
  { return bookNo_; }
  [[nodiscard]]
  virtual double net_price(std::size_t n) const
  { return price_ * static_cast<double>(n); }
  virtual ~Quote() = default;

private:
  std::string bookNo_;

protected:
  double price_ = 0.0;
};


inline
void print_total(
    std::ostream &ostrm,
    const Quote &item,
    std::size_t n
    )
{
  double ret = item.net_price(n);
  ostrm << "ISBN: " << item.isbn()
     << " # sold: " << n 
     << " total due: " << ret 
     << '\n';
}


