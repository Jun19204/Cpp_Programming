#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"
#include "Quote/Basket.h"

#include <cstdlib>
#include <iostream>

int main()
{
  Basket basket;

  basket.addItem(Quote("111", 5000));
  basket.addItem(Bulk_quote("222", 5000, 5, 0.5));
  basket.totalReceipt(std::cout);

  return EXIT_SUCCESS;
}
