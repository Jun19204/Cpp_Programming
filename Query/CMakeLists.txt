
##### < 1. 라이브러리 생성> #####
# 구현체 소스들로 정적 라이브러리(libQuery.a) 타깃 생성
add_library(Query
    STATIC
    Query.cc
)
# 해더 파일이 위치한 디렉토리 경로 설정
target_include_directories(Query
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} # 헤더가 현재 디렉토리에 있는 경우
)


##### < 2. 실행파일 생성> #####
# main함수가 포함된 소스로 실행파일 타깃 생성
add_executable(Query_exe
    main.cc
)
# 라이브러리 연결 및 include 자동 전파
target_link_libraries(Query_exe
    PRIVATE
    Query
)
