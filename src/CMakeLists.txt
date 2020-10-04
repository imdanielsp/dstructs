cmake_minimum_required(VERSION 2.6.2)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        #src/timer.cpp
        DStructs.h
        Linked_List/linked_list.h
        Dynamic_Array/dynamic_array.h
        Queue/queue.h
        Queue/deque.h
        Binary_Search_Tree/binary_tree_node.h
        Binary_Search_Tree/binary_search_tree.h
#       src/AVL_Tree/avl_node.h
#        src/AVL_Tree/avl_tree.h
        Insertion_Sort/insertion_sort.h
        Hash_Table/hash_table.h
        Stack/stack.h
#        Linked_List/doubly_linked_list.h
#        Linked_List/doubly_node.h
        Functional/functional.h
        Heap/heap.h
        Smart_Pointer/shared_ptr.h
        Graph/graph.h
)


add_executable(dstructs ${SOURCE_FILES})
