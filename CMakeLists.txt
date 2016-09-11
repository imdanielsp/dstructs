cmake_minimum_required(VERSION 3.6)
project(DStructs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include/)
link_directories(/usr/local/lib/)
link_libraries(gtest)

set(SOURCE_FILES src/Linked_List/node.h test/node_test.cc test/test_main.cc)

add_executable(DStructs ${SOURCE_FILES})