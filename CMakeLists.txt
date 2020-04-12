cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(LeetCode
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "Leet Code problems")

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)

add_executable(LeetCode src/main.cpp)
