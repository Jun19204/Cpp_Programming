// 함수 포인터 사용해보기
#include <cstdlib>
#include <vector>
#include <iostream>
#include <format>
#include <print>

using FuncPtr = int(*)(const int&, const int&);
std::vector<FuncPtr> func_vector;

int sum(const int& a, const int& b) { return a+b; }
int sub(const int& a, const int& b) { return a-b; }
int multiple(const int& a, const int& b) { return a*b; }
int division(const int& a, const int& b) { return a/b; }

int main()
{
    func_vector.push_back(&sum);
    func_vector.push_back(&sub);
    func_vector.push_back(&multiple);
    func_vector.push_back(&division);

    for (auto func : func_vector) {
        auto result = func(10, 2);
        std::cout << result << '\n';
        std::cout << std::format("{}\n", result);
        std::print("{}\n", result);
    }

    return EXIT_SUCCESS;
}
