# CMake generated Testfile for 
# Source directory: C:/Users/ferna/CLionProjects/LinearAlgebra/Tests
# Build directory: C:/Users/ferna/CLionProjects/LinearAlgebra/cmake-build-debug/Tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("C:/Users/ferna/CLionProjects/LinearAlgebra/cmake-build-debug/Tests/LinearAlgebraTests[1]_include.cmake")
add_test([=[LinearAlgebraTests]=] "C:/Users/ferna/CLionProjects/LinearAlgebra/cmake-build-debug/Tests/LinearAlgebraTests.exe")
set_tests_properties([=[LinearAlgebraTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ferna/CLionProjects/LinearAlgebra/Tests/CMakeLists.txt;34;add_test;C:/Users/ferna/CLionProjects/LinearAlgebra/Tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
