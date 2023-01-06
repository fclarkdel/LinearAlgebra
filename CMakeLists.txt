cmake_minimum_required(VERSION 3.24)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        LinearAlgebraTest

        Headers/LinearAlgebra.h
        Headers/Exceptions/InvalidDimensionsException.h
        Headers/Exceptions/SingularMatrixException.h
        Sources/LinearAlgebra.cpp
        Sources/Exceptions/InvalidDimensionsException.cpp
        Sources/Exceptions/SingularMatrixException.cpp
        Tests/AddTest.cpp
        Tests/ScalarTest.cpp
        Tests/SubtractTest.cpp
        Tests/BuildTest.cpp
        Tests/IdentityTest.cpp
        Tests/RowTest.cpp
        Tests/ColumnTest.cpp
)
target_include_directories(
        LinearAlgebraTest

        PRIVATE

        Headers
)
target_link_libraries(
        LinearAlgebraTest

        GTest::gtest_main
)
include(GoogleTest)

gtest_discover_tests(LinearAlgebraTest)

#add_executable(
#        Test
#
#        Headers/Exceptions/InvalidDimensionsException.h
#        Headers/Exceptions/SingularMatrixException.h
#        Headers/LinearAlgebra.h
#
#        Sources/Exceptions/InvalidDimensionsException.cpp
#        Sources/Exceptions/SingularMatrixException.cpp
#        Sources/LinearAlgebra.cpp
#
#        main.cpp
#        hello_test.cpp
#)
#add_library(
#        LinearAlgebra
#
#        STATIC
#
#        Headers/Exceptions/InvalidDimensionsException.h
#        Headers/Exceptions/SingularMatrixException.h
#        Headers/LinearAlgebra.h
#
#        Sources/Exceptions/InvalidDimensionsException.cpp
#        Sources/Exceptions/SingularMatrixException.cpp
#        Sources/LinearAlgebra.cpp
#)
#target_include_directories(
#        Test
#
#        PRIVATE
#
#        Headers
#)
#target_include_directories(
#        LinearAlgebra
#
#        PRIVATE
#
#        Headers
#)