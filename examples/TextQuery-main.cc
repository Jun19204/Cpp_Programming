#include "Query/TextQuery.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[]) 
{
  if (argc < 1) {
    return EXIT_FAILURE;
  }
  const char* file_name = argv[1];
  ifstream infile(file_name);

  runQueries(infile);

  return EXIT_SUCCESS;
}
