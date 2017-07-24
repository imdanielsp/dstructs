cmake_minimum_required(VERSION 2.8.7)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
link_libraries(gtest)

set(TEST_FILES
        test_main.cc
        binary_searc_tree_test.cc
        binary_tree_node_test.cc
        deque_test.cc
        dynamic_array_test.cc
        linked_list_test.cc
        node_test.cc
        queue_test.cc
        stack_test.cc)

add_executable(dstructs-test ${TEST_FILES})
