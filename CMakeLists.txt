cmake_minimum_required(VERSION 3.24)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Test
        test.cpp
        Sources/LinearAlgebra.cpp
        Headers/LinearAlgebra.h
)
add_library(
        LinearAlgebra
        STATIC
        Sources/LinearAlgebra.cpp
        Headers/LinearAlgebra.h
)
target_include_directories(
        Test
        PRIVATE
        Headers
)