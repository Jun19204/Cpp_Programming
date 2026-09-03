#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"

#include <cstdlib>
#include <iostream>

int main()
{
  Quote quote{"11111", 5000};
  Bulk_quote bulkQuote{"22222", 6000, 5, 0.3};

  print_total(std::cout, quote, 10);
  print_total(std::cout, bulkQuote, 10); 

  std::cout << "\n";

  Quote *ptr1 = &quote;
  Quote *ptr2 = &bulkQuote;
  ptr1->debug(std::cout);
  ptr2->debug(std::cout);

  return EXIT_SUCCESS;
}
