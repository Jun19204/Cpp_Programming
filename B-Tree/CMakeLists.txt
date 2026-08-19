add_library(B-Tree
    STATIC
    B-Tree.cc
)
target_include_directories(B-Tree
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(B-Tree_exe
    main.cc
)
target_link_libraries(B-Tree_exe
    PRIVATE
    B-Tree
)
