#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

int get_sum_vec(std::vector<std::string> &vec)
{
    int sum{0};
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        auto pos = iter->find_first_of("+-0123456789");
        if (pos != std::string::npos) {
            sum += std::stoi(iter->substr(pos));
        }
    }
    return sum;
}

int main(void)
{
    std::vector<std::string> vec = {"dkdk100", "dd24", "ff15", "d70", "d55"};
    int result = get_sum_vec(vec);
    
    std::cout << "result = " << result << std::endl;

    return EXIT_SUCCESS;
}
