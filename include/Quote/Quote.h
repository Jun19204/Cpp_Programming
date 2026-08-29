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
private:
  std::string bookNo;
protected:
  double price = 0.0;
};


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


