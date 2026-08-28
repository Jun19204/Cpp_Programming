# ============================================================
# Examples(executable)
# ============================================================

add_executable(
  Query_app
  query-main.cc
)
target_link_libraries(
  Query_app
  PRIVATE
  Query_lib
  project_warnings
  project_sanitizers
)

add_executable(
  word_transform_app
  word_transform-main.cc
)
target_link_libraries(
  word_transform_app
  PRIVATE
  project_warnings
  project_sanitizers
)

add_executable(
  throw_error_app
  throw_error-main.cc
)
target_link_libraries(
  throw_error_app
  PRIVATE
  error_code_lib
  project_warnings
  project_sanitizers
)


