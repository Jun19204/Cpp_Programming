# CMake generated Testfile for 
# Source directory: /home/thoma/C++programming
# Build directory: /home/thoma/C++programming/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Test_Sales_data]=] "Sales_data_exe")
set_tests_properties([=[Test_Sales_data]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/thoma/C++programming/CMakeLists.txt;32;add_test;/home/thoma/C++programming/CMakeLists.txt;0;")
add_test([=[Test_StrBlob]=] "StrBlob_exe")
set_tests_properties([=[Test_StrBlob]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/thoma/C++programming/CMakeLists.txt;33;add_test;/home/thoma/C++programming/CMakeLists.txt;0;")
subdirs("Sales_data")
subdirs("StrBlob")
