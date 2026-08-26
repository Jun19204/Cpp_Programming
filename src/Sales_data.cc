#include "myproject/Sales_data.h"

using namespace std;

// 멤버 함수 정의

inline Sales_data& Sales_data::combine(const Sales_data &rhs) 
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

inline double Sales_data::avg_price() const 
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0.0;
}

// 프랜드 함수 정의

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) 
{
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

ostream &print(ostream &os, const Sales_data &item) 
{
  os << item.isbn() << " " << item.units_sold 
     << " " << item.revenue << " " << item.avg_price();
  return os;
}

istream &read(istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

istream &operator>>(istream &is, Sales_data &rhs) 
{
  Sales_data temp;
  double price{0.0};
  if (is >> temp.bookNo >> temp.units_sold >> price) {
    temp.revenue = temp.units_sold * price;
    rhs = std::move(temp);
  }
  return is;
}


