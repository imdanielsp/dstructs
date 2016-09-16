cmake_minimum_required(VERSION 2.8.7)
project(DStructs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include/)
link_directories(/usr/local/lib/)
link_libraries(gtest)

set(SOURCE_FILES src/Linked_List/node.h test/node_test.cc test/test_main.cc src/Linked_List/linked_list.cc
        src/Linked_List/linked_list.h test/linked_list_test.cc)

add_executable(dstructs-test ${SOURCE_FILES})