add_library(StrVec
    STATIC
    StrVec.cc
)
target_include_directories(StrVec
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

