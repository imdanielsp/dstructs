#ifndef DSTRUCTS_GRAPH_H
#define DSTRUCTS_GRAPH_H

#include <memory>

#include "../Dynamic_Array/dynamic_array.h"

namespace DStructs {

template <class T>
struct GNode;

template <class T>
using GNodePtr = std::shared_ptr<GNode<T>>;

template <class T>
struct GNode {
    T _item;

    DynamicArray<GNodePtr<T>> _edges;
};

template <class T>
class Graph {
    Graph() {}

    ~Graph() {}

    

private:
    GNodePtr<T> _root;
};

}

#endif // DSTRUCTS_GRAPH_H
