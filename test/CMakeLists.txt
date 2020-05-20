cmake_minimum_required(VERSION 3.17)

add_executable(
  LeetCodeTests
  easyproblems_tests.cpp mediumproblem_tests.cpp hardproblem_tests.cpp
)

target_include_directories(
  LeetCodeTests
  PUBLIC ../include/easy ../include/medium ../include/hard
)

target_link_libraries(LeetCodeTests PUBLIC gtest_main)

add_test(
  NAME LeetCode_Test
  COMMAND LeetCodeTests
)
