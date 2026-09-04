#pragma once

#include <algorithm>
#include <cstddef>
#include <ostream>
#include <string>
#include <utility>


class Quote { // 기초 클래스
public:
  Quote() = default;
  Quote(
      const std::string &book, 
      double sales_price
      )
    : bookNo_(book), price_(sales_price)
  { }
  Quote(const Quote&) = default;
  Quote(Quote&&) noexcept = default;
  Quote& operator=(const Quote&) & = default;
  Quote& operator=(Quote&&) & noexcept = default;
  [[nodiscard]]
  std::string isbn() const
  { return bookNo_; }
  [[nodiscard]]
  virtual double net_price(std::size_t n) const
  { return price_ * static_cast<double>(n); }
  [[nodiscard]]
  virtual Quote* clone() const & { return new Quote(*this); }
  [[nodiscard]]
  virtual Quote* clone() && { return new Quote(std::move(*this)); }


  virtual ~Quote() = default;

private:
  std::string bookNo_;

protected:
  double price_ = 0.0;
};


inline
double printTotal(
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
  return ret;
}


