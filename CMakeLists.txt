cmake_minimum_required(VERSION 3.24)

set(This LinearAlgebra)

project(${This})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers

    Headers/Exceptions/InvalidDimensionsException.h
    Headers/Exceptions/SingularMatrixException.h
    Headers/LinearAlgebra.h
)
set(Sources

    Sources/Exceptions/InvalidDimensionsException.cpp
    Sources/Exceptions/SingularMatrixException.cpp
    Sources/LinearAlgebra.cpp
)
add_library(
    ${This}

    STATIC

    ${Headers}

    ${Sources}
)
include_directories(Headers)

enable_testing()

add_subdirectory(Tests)