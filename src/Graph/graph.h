#ifndef DSTRUCTS_GRAPH_H
#define DSTRUCTS_GRAPH_H

#include <memory>
#include <unordered_set>

namespace DStructs::graph {
template<class T>
struct node;

template<class T>
using node_ptr = std::shared_ptr<node<T>>;

template<class T>
class graph;

template<class T>
class graph
{
public:
    using value_type = T;
    using element_type = node<value_type>;
    using element_ptr_type = node_ptr<value_type>;
    using container_type = std::unordered_set<element_ptr_type>;
    using predicate_type =
        std::function<bool(element_ptr_type, element_ptr_type)>;

    graph() = default;
    virtual ~graph() = default;

    // Accesors
    const container_type& get_vertices() const { return _vertices; }

    // Modifiers
    void add_vertex(element_ptr_type v)
    {
        if (!has_pointer(v)) {
            _vertices.push_back(v);
        }
    }

    void add_edge(element_ptr_type dest, element_ptr_type src)
    {
        assert(dest);
        assert(src);

        dest->add_edge(src);
    }

    // Creational methods
    element_ptr_type make_vertex()
    {
        auto vertex = std::make_shared<element_type>();
        _vertices.push_back(vertex);
        return vertex;
    }

    element_ptr_type make_vertex(const value_type& value)
    {
        auto vertex = std::make_shared<element_type>(value);
        _vertices.push_back(vertex);
        return vertex;
    }

    element_ptr_type make_vertex(value_type&& value)
    {
        auto vertex = std::make_shared<element_type>(std::move(value));
        _vertices.insert(vertex);
        return vertex;
    }

    // Traversal strategy
    template<typename Comp>
    struct bfs
    {
        bool operator()(predicate_type pred,
                        element_ptr_type src,
                        element_ptr_type dest)
        {
            assert(src);
            assert(dest);

            Comp comp;
            std::set<element_ptr_type> visited;
            std::deque<element_ptr_type> q;
            q.push_back(src);

            while (!q.empty()) {
                auto curr = q.front();
                q.pop_front();

                if (comp(dest, curr)) {
                    return true;
                } else {
                    for (const auto& edge : curr->get_edges()) {
                        if (visited.count(edge) == 0 && pred(curr, edge)) {
                            visited.insert(curr);
                            q.push_back(edge);
                        }
                    }
                }
            }

            return false;
        }
    };

    // TODO: Implement depth-first search
    struct dfs
    {};

    // Traversal
    template<typename Strategy = bfs<std::equal_to<element_ptr_type>>>
    bool traverse(element_ptr_type src,
                  element_ptr_type dest,
                  predicate_type pred)
    {
        if (!src && _vertices.empty()) {
            return false;
        }

        return Strategy()(pred, src, dest);
    }

    // Visualization methods
    void print_graph() const
    {
        for (typename decltype(_vertices)::size_type idx = 0;
             idx < _vertices.size();
             idx++) {
            _vertices[idx]->print_node();
        }
    }

private:
    bool has_pointer(element_ptr_type ptr) { return _vertices.count(ptr) != 0; }

    container_type _vertices;
};

template<class T>
struct node
{
    using value_type = T;
    using container_type = std::vector<node_ptr<value_type>>;

    node() = default;

    explicit node(const value_type& t)
        : _item(t)
    {}

    explicit node(value_type&& t)
        : _item(t)
    {}

    void print_node() const
    {
        std::cout << "[ " << _item << " ] -> [ ";

        for (typename decltype(_edges)::size_type idx = 0; idx < _edges.size();
             idx++) {
            std::cout << _edges[idx]->_item;

            if (_edges.size() - 1 != idx)
                std::cout << ", ";
        }

        std::cout << " ]" << std::endl;
    }

    void set_value(const value_type& value) { _item = value; }
    void set_value(value_type&& value) { _item = value; }

    value_type get_value() const { return _item; }
    const value_type& get_const_value() const { return _item; }

    const container_type& get_edges() const { return _edges; }

private:
    friend graph<value_type>;

    void add_edge(node_ptr<value_type> edge)
    {
        assert(edge);
        _edges.push_back(edge);
    }

    value_type _item;
    std::vector<node_ptr<value_type>> _edges;
};

} // namespace DStructs::graph

#endif // DSTRUCTS_GRAPH_H
