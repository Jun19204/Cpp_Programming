# ============================================================
# Examples(executable)
# ============================================================

add_executable(
  Query_app
  Query-main.cc
)
target_include_directories(
  Query_app
  PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
  Query_app
  PRIVATE
  Query_lib
  project_warnings
  project_sanitizers
)

add_executable(
  Quote_app
  Quote-main.cc
)
target_include_directories( # Quote.h, Bulk_quote.h, Disc_quote.h가 header-only이기 때문
  Quote_app
  PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
  Quote_app
  PRIVATE
  Basket_lib
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


