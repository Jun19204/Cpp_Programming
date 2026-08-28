#include "error_code/error_code.h"
#include <cstdlib>
#include <iostream>

int main(void) 
{
  try {
    throw error{
      error_code::file_open_failed,
      {
        {"path", "config.json"}, 
        {"reason", "Permission denied"}
      }
    };
  } 
  catch (const error &e) {
    std::cout << e.what() << '\n';
  }

  return EXIT_SUCCESS;
}
