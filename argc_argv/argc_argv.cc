#include <cstdlib>
#include <cstddef>
#include <iostream>

int main(int argc, char **argv)
{
    for (size_t i = 1; argv[i] != nullptr; ++i) {  
        std::cout << argv[i] << std::endl;
    }
    return EXIT_SUCCESS;
}
