#pragma once

#include <istream>
#include <string>

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);

public:
  // 생성자
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &is) {
    double price = 0;
    is >> bookNo >> units_sold >> price;
    revenue = price * units_sold;
  }
  // 복사제어 
  Sales_data(const Sales_data &) = default;
  Sales_data(Sales_data &&) = default;
  Sales_data& operator=(const Sales_data &) = default;
  Sales_data& operator=(Sales_data &&) = default;
  ~Sales_data() = default;

  // 멤버 함수
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  double avg_price() const;

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// 프랜드 함수 선언
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
