cmake_minimum_required(VERSION 3.25)
project(CppPractice VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # coc.nvim/clangd 자동완성용

# 빌드 타입을 지정하지 않은 경우 기본값을 Debug로 설정
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# 디버그 빌드 시 GDB 및 Valgrind를 위한 최적화 억제 및 상세 디버그 심볼 포함
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0 -fno-omit-frame-pointer")

if(MSVC)
    add_compile_options(/W4 /permissive- /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wconversion -Wsign-conversion -ftemplate-backtrace-limit=0)
endif()

enable_testing()

# Valgrind 옵션 설정 (MemoryCheck)
set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1")
include(CTest)

# 각 서브 타겟을 CTest 등록 (예: Sales_data_exe)
#add_test(NAME Test_Sales_data COMMAND Sales_data_exe)
#add_test(NAME Test_StrBlob COMMAND StrBlob_exe)
#add_test(NAME Test_Query COMMAND Query_exe)
#add_test(NAME Test_B-Tree COMMAND B-Tree_exe)
#add_test(NAME Test_Mail COMMAND Mail_exe)
add_test(NAME Test_StrVec COMMAND StrVec_exe)

# 등록하고 싶은 연습 문제 폴더들 추가
#add_subdirectory(Sales_data)
#add_subdirectory(StrBlob)
#add_subdirectory(Query)
#add_subdirectory(B-Tree)
#add_subdirectory(MailProgram)
add_subdirectory(StrVec)
# 필요할 때 새로운 폴더를 만들어 add_subdirectory(새폴더) 추가
