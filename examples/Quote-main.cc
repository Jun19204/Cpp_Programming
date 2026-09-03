#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

int main()
{
  std::vector<Quote> valueVec;
  std::vector<std::shared_ptr<Quote>> shptrVec;

  valueVec.push_back(Quote("111", 5000));
  // Object Slicing 발생
  valueVec.push_back(Bulk_quote("222", 5000, 5, 0.5));
  for (const auto& element : valueVec) {
    std::cout << element.isbn() << " "
              << element.net_price(10) << '\n';
  }

  std::cout << '\n';

  shptrVec.push_back(std::make_shared<Quote>("111", 5000));
  // shared_ptr도 Derived-to-Base 변환이 가능
  shptrVec.push_back(std::make_shared<Bulk_quote>("222", 5000, 5, 0.5));
  for (const auto& element : shptrVec) {
    std::cout << element->isbn() << " "
              << element->net_price(10) << '\n';
  }

  return EXIT_SUCCESS;
}
