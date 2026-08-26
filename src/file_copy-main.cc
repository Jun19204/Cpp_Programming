#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void copy_stream(std::string_view, std::string_view);
std::istream& read(std::istream&, std::string&);
std::ostream& print(std::ostream&, std::string&);

std::istream& read(std::istream& is, std::string& str)
{
    while(is >> str);
    return is;
}

std::ostream& print(std::ostream& os, std::string& str)
{
    while(os << str);
    return os;
}

void copy_stream(std::string_view fname1, std::string_view fname2)
{
    std::ifstream origin_file(fname1.data(), std::ios::binary);
    std::ofstream clone_file(fname2.data(), std::ios::binary);

    if (!origin_file) {
        std::cerr << "원본 파일 열기 실패: " << fname1 << '\n';
        return;
    }
    if (!clone_file) {
        std::cerr << "대상 파일 생성 실패: " << fname2 << '\n';
        return;
    }

    // 스트림 버퍼 전체를 한 번에 대상 파일로 밀어넣음
    clone_file << origin_file.rdbuf(); 
    std::cout << "파일 복사 성공: " << fname2 << '\n';
}

int main(const int argc, const char** argv)
{
    if (argc < 2) return EXIT_FAILURE;
    for (auto p = argv + 2; p != argv + argc; ++p) {
        copy_stream(argv[1], *p);
    }
    return EXIT_SUCCESS;
}
