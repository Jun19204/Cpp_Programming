#include "error_code/error_code.h"

#include <string_view>
#include <utility>


// 표준 에러 메시지
// 호출자가 반환값을 무시하면 컴파일러 경고
// 반환값을 반드시 확인해야하는 함수에 붙임
[[nodiscard]]
constexpr auto message_of(error_code code) noexcept 
-> std::string_view
{
  switch (code) {
  case error_code::file_open_failed:
    return "Failed to open file";

  case error_code::file_read_failed:
    return "Failed to read file";

  case error_code::parse_failed:
    return "Failed to parse input";

  case error_code::invalid_argument:
    return "Invalid argument";
  }

  std::unreachable();
}


// 로그 출력용 메시지
// 헤더와 구현 파일 내부에서만 사용하고 
// 외부로는 공개하지않는 헬퍼 함수이므로
// inline이어도 헤더에서 정의하지 않아도 된다.
[[nodiscard]]
constexpr auto name_of(error_code code) noexcept 
-> std::string_view
{
  switch (code) {
  case error_code::file_open_failed:
    return "FILE_OPEN_FAILED";
  
  case error_code::file_read_failed:
    return "FILE_READ_FAILED";

  case error_code::parse_failed:
    return "PARSE_FAILED";

  case error_code::invalid_argument:
    return "INVALID_ARGUMENT";
  }

  std::unreachable();
}


std::string
error::build_message(
    error_code code, 
    const std::vector<error_context>& contexts
)
{
  std::string result;
    
  result += "[";
  result += name_of(code);
  result += "] ";
  result += message_of(code);
    
  for (const auto& [key, value] : contexts) {
    result += "\n ";
    result += key;
    result += ": ";
    result += value;
  }
    
  return result;
}




