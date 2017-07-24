cmake_minimum_required(VERSION 2.8.7)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        #src/timer.cpp
        DStructs.h
        Linked_List/node.h
        Linked_List/linked_list.h
        Dynamic_Array/dynamic_array.h
        Queue/queue.h
        Queue/deque.h
        Binary_Search_Tree/binary_tree_node.h
        Binary_Search_Tree/binary_search_tree.h
#        src/AVL_Tree/avl_node.cc
#        src/AVL_Tree/avl_node.h
#        src/AVL_Tree/avl_tree.cc
#        src/AVL_Tree/avl_tree.h
        Insertion_Sort/insertion_sort.h
        Hash_Table/hash_table.cc
        Hash_Table/hash_table.h)


add_executable(dstructs ${SOURCE_FILES})