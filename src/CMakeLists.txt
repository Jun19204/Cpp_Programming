# ============================================================
# Core Libraries
# ============================================================

add_library(Mail_lib STATIC mail.cc)
add_library(Sales_data_lib STATIC Sales_data.cc)
add_library(StrBlob_lib STATIC StrBlob.cc)
add_library(StrVec_lib STATIC StrVec.cc)
add_library(Query_lib STATIC Query.cc)

target_link_libraries(
  Query_lib
  PRIVATE
  StrVec_lib
)

set(
  ALL_LIBS
  Mail_lib
  Sales_data_lib
  StrBlob_lib
  StrVec_lib
  Query_lib
)

foreach(lib IN LISTS ALL_LIBS)
  target_include_directories(
    ${lib}
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
  )

  target_link_libraries(
    ${lib}
    PRIVATE
    project_warnings
    project_sanitizers
  )
endforeach()

