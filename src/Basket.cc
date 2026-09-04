#include "Basket/Basket.h"
#include "Quote/Quote.h"
#include "Quote/Bulk_quote.h"

using namespace std;

double
Basket::totalReceipt(ostream &ostrm) const {
  double sum{0.0};
  for (auto iter = items_.cbegin();
            iter != items_.cend();
            iter = items_.upper_bound(*iter)) {
    sum += printTotal(ostrm, **iter, items_.count(*iter));
  }
  ostrm << "Total Sale: " << sum << '\n';
  return sum;
}


