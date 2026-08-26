#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <string_view>

namespace fs = std::filesystem;

// 파일 복사를 담당하는 함수
void fcopy(std::string_view source, std::string_view destination) 
{
    std::error_code ec;
    
    // 복사 옵션 설정 (필요시 덮어쓰기 허용 등)
    auto options = fs::copy_options::overwrite_existing;
    
    // 예외(Exception) 대신 error_code를 사용하여 안전하게 에러 처리
    if (!fs::copy_file(source, destination, options, ec)) {
        std::cerr << " 파일 복사 실패: " << destination 
                  << " (" << ec.message() << ")\n";
    } else {
        std::cout << " 파일 복사 성공: " << destination << "\n";
    }
}

int main(int argc, char** argv) 
{
    // C++20: 포인터 연산 대신 std::span을 사용하여 인수를 안전하게 래핑
    std::span<char*> args(argv, static_cast<std::size_t>(argc));

    if (args.size() < 3) {
        std::cerr << "사용법: " << args[0] << " <원본_파일> <대상_파일1> [대상_파일2...]\n";
        return EXIT_FAILURE;
    }

    std::string_view source_file = args[1];
    
    // C++20: 첫 두 인수를 제외한 나머지 대상 파일들의 subspan 생성
    auto destinations = args.subspan(2);

    // 범위 기반 for문으로 간결하게 순회
    for (std::string_view dest : destinations) {
        fcopy(source_file, dest);
    }

    return EXIT_SUCCESS;
}
