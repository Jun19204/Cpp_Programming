get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${DIR_NAME})

file(GLOB SOURCES "*.cpp" "*.cc" "*.hpp" "*.h")
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
