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
  std::string isbn() const
  { return bookNo_; }
  virtual double net_price(std::size_t n) const
  { return price_ * static_cast<double>(n); }
  virtual ~Quote() = default;
  virtual void debug(std::ostream &os) const
  { os << bookNo_ << " " << price_ << "\n"; }
private:
  std::string bookNo_;
protected:
  double price_ = 0.0;
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


