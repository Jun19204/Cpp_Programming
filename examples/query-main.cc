#include "Query/Query.h"

#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[]) 
{
  if (argc < 1)
    return EXIT_FAILURE;
  auto file_name = argv[1];
  ifstream infile(file_name);

  runQueries(infile);

  return EXIT_SUCCESS;
}
