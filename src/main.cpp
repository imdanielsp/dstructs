#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>

#include "Graph/graph.h"

using namespace DStructs::graph;

struct step
{
    step(std::pair<int, int> pos, bool blocked = false)
        : _pos(pos)
        , _blocked(blocked)
    {}

    std::pair<int, int> _pos;
    bool _blocked;
};

std::ostream&
operator<<(std::ostream& os, const step& s)
{
    os << "(" << s._pos.first << ", " << s._pos.second << ")";
    return os;
}

void
print_path(
    std::map<graph<step>::element_ptr_type, graph<step>::element_ptr_type> pred,
    const graph<step>::element_ptr_type dest);

std::string
compute_move(const graph<step>::element_ptr_type src,
             const graph<step>::element_ptr_type dest);

int
main()
{
    auto g = std::make_shared<graph<step>>();
    auto _0_0 = g->make_vertex(std::move(step({ 0, 0 })));
    auto _0_1 = g->make_vertex(std::move(step({ 0, 1 })));
    auto _0_2 = g->make_vertex(std::move(step({ 0, 2 })));

    auto _1_0 = g->make_vertex(std::move(step({ 1, 0 })));
    auto _1_1 = g->make_vertex(std::move(step({ 1, 1 }, true)));
    auto _1_2 = g->make_vertex(std::move(step({ 1, 2 }, true)));

    auto _2_0 = g->make_vertex(std::move(step({ 2, 0 })));
    auto _2_1 = g->make_vertex(std::move(step({ 2, 1 })));
    auto _2_2 = g->make_vertex(std::move(step({ 2, 2 })));

    g->add_edge(_0_0, _0_1);
    g->add_edge(_0_0, _1_0);

    g->add_edge(_0_1, _0_0);
    g->add_edge(_0_1, _0_2);
    g->add_edge(_0_1, _1_1);

    g->add_edge(_0_2, _0_1);
    g->add_edge(_0_2, _1_2);

    g->add_edge(_1_0, _0_0);
    g->add_edge(_1_0, _1_1);
    g->add_edge(_1_0, _2_0);

    g->add_edge(_1_1, _0_1);
    g->add_edge(_1_1, _1_0);
    g->add_edge(_1_1, _1_2);
    g->add_edge(_1_1, _2_1);

    g->add_edge(_1_2, _0_2);
    g->add_edge(_1_2, _1_1);
    g->add_edge(_1_2, _2_2);

    g->add_edge(_2_0, _1_0);
    g->add_edge(_2_0, _2_1);

    g->add_edge(_2_1, _2_0);
    g->add_edge(_2_1, _2_2);
    g->add_edge(_2_1, _1_1);

    g->add_edge(_2_2, _1_2);
    g->add_edge(_2_2, _2_1);

    auto vertices = g->get_vertices();

    std::map<graph<step>::element_ptr_type, graph<step>::element_ptr_type> pred;

    auto status = g->traverse(_0_0, _2_2, [&pred](auto curr, auto edge) {
        bool accept = false;
        if (edge->get_value()._blocked == false) {
            accept = true;
            pred.insert({ edge, curr });
        }
        return accept;
    });

    if (status) {
        std::cout << "found it!" << std::endl;
    } else {
        std::cout << "no found!" << std::endl;
    }

    print_path(pred, _2_2);

    return 0;
}

std::string
compute_move(const graph<step>::element_ptr_type src,
             const graph<step>::element_ptr_type dest)
{
    auto src_val = src->get_value();
    auto dst_val = dest->get_value();

    if ((src_val._pos.first - dst_val._pos.first) > 0) {
        return "N";
    } else if ((src_val._pos.first - dst_val._pos.first) < 0) {
        return "S";
    } else if ((src_val._pos.second - dst_val._pos.second) > 0) {
        return "W";
    } else if ((src_val._pos.second - dst_val._pos.second) < 0) {
        return "E";
    } else {
        assert(false);
        return "";
    }
}

void
print_path(
    std::map<graph<step>::element_ptr_type, graph<step>::element_ptr_type> pred,
    const graph<step>::element_ptr_type dest)
{
    std::list<std::string> path;
    auto curr = dest;

    while (curr && pred[curr]) {
        path.push_front(compute_move(pred[curr], curr));
        curr = pred[curr];
    }

    std::for_each(
        path.begin(), path.end(), [](auto p) { std::cout << p << std::endl; });
}
