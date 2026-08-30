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
    : bookNo(book), price(sales_price)
  { }
  std::string isbn() const
  { return bookNo; }
  virtual double net_price(std::size_t n) const
  { return price * static_cast<double>(n); }
  virtual ~Quote() = default;
  virtual void debug(std::ostream &os) const
  { os << bookNo << " " << price << "\n"; }
private:
  std::string bookNo;
protected:
  double price = 0.0;
};


inline
void print_total(
    std::ostream &os,
    const Quote &item,
    std::size_t n
    )
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
     << " # sold: " << n 
     << " total due: " << ret 
     << std::endl;
}


