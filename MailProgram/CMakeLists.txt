add_library(Mail
    STATIC
    Mail.cc
)
target_include_directories(Mail
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
