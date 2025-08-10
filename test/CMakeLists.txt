cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
        LeetCodeTests
        easyproblems_tests.cpp
        mediumproblem_tests.cpp
        hardproblem_tests.cpp
        common_tests.cpp
)

target_include_directories(
        LeetCodeTests
        PUBLIC ../include/easy ../include/medium ../include/hard
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)
target_link_libraries(LeetCodeTests PUBLIC GTest::gtest_main)

add_test(
        NAME LeetCode_Test
        COMMAND LeetCodeTests
)
