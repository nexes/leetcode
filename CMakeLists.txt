cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_BUILD_TYPE Debug)

project(LeetCode
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "Leet Code problems")

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/e39786088138f2749d64e9e90e0f9902daa77c40.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)

add_executable(LeetCode src/main.cpp)
