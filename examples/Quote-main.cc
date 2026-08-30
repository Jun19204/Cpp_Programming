#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"

#include <cstdlib>
#include <iostream>

int main(void)
{
  Quote q{"11111", 5000};
  Bulk_quote bq{"22222", 6000, 5, 0.3};

  print_total(std::cout, q, 10);
  print_total(std::cout, bq, 10); 

  std::cout << "\n";

  Quote *ptr1 = &q, *ptr2 = &bq;
  ptr1->debug(std::cout);
  ptr2->debug(std::cout);

  return EXIT_SUCCESS;
}
