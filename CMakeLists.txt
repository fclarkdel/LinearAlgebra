cmake_minimum_required(VERSION 3.24)

project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Test

        Headers/Exceptions/InvalidDimensionsException.h
        Headers/Exceptions/SingularMatrixException.h
        Headers/LinearAlgebra.h

        Sources/Exceptions/InvalidDimensionsException.cpp
        Sources/Exceptions/SingularMatrixException.cpp
        Sources/LinearAlgebra.cpp

        test.cpp
)
add_library(
        LinearAlgebra

        STATIC

        Headers/Exceptions/InvalidDimensionsException.h
        Headers/Exceptions/SingularMatrixException.h
        Headers/LinearAlgebra.h

        Sources/Exceptions/InvalidDimensionsException.cpp
        Sources/Exceptions/SingularMatrixException.cpp
        Sources/LinearAlgebra.cpp
)
target_include_directories(
        Test

        PRIVATE

        Headers
)
target_include_directories(
        LinearAlgebra

        PRIVATE

        Headers
)