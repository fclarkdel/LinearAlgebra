cmake_minimum_required(VERSION 3.24)

set(This LinearAlgebraTests)

project(${This})

set(Sources

    AddTest.cpp
    ScalarTest.cpp
    SubtractTest.cpp
    BuildTest.cpp
    IdentityTest.cpp
    RowTest.cpp
    ColumnTest.cpp
    MultiplyTest.cpp
    TransposeTest.cpp
    DeterminantTest.cpp
    InverseTest.cpp
)
add_executable(
        ${This}

        ${Sources}
)
target_link_libraries(
        ${This}

        PUBLIC

        LinearAlgebra
        gtest_main
)
add_test(
    NAME ${This}
    COMMAND ${This}
)
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

gtest_discover_tests(${This})