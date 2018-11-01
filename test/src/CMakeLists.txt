cmake_minimum_required(VERSION 3.10.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../src/)
link_libraries(gtest gtest_main)

file(GLOB TEST_FILES *.cc)


add_executable(dstructs-test ${TEST_FILES})
