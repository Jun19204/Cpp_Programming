#include "Query/Query.h"

#include <cstdlib>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <file>\n";
    return EXIT_FAILURE;
  }

  std::ifstream infile(argv[1]);

  if (!infile) {
    std::cerr << "Cannot open file: "
              << argv[1] << '\n';
    return EXIT_FAILURE;
  }

  TextQuery text(infile);
  Query q =
      (Query("fiery") & Query("bird")) | Query("wind");

  std::cout << q << '\n';

  const auto result = q.eval(text);

  print(std::cout, result);

  return EXIT_SUCCESS;
}
