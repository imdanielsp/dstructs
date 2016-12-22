cmake_minimum_required(VERSION 2.8.7)
project(DStructs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include/)
link_directories(/usr/local/lib/)
link_libraries(gtest)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES    #src/main.cpp
                    src/timer.cpp
                    src/DStructs.h
                    src/Linked_List/node.h
                    src/Linked_List/linked_list.h
                    src/Dynamic_Array/dynamic_array.h
                    src/Queue/queue.h
                    src/Queue/deque.h
                    src/Binary_Search_Tree/binary_tree_node.h
                    src/Binary_Search_Tree/binary_search_tree.h
#                    src/AVL_Tree/avl_node.cc
#                    src/AVL_Tree/avl_node.h
#                    src/AVL_Tree/avl_tree.cc
#                    src/AVL_Tree/avl_tree.h
#                    test/test_main.cc
                    test/node_test.cc
                    test/linked_list_test.cc
                    test/queue_test.cc
                    test/dynamic_array_test.cc
                    test/deque_test.cc
                    test/binary_tree_node_test.cc
                    test/binary_searc_tree_test.cc
        )

add_executable(dstructs ${SOURCE_FILES})
