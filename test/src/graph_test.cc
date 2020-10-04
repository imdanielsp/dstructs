#include <gtest/gtest.h>

#include "Graph/graph.h"

using namespace DStructs::graph;

class GraphTest : public testing::Test
{
protected:
    virtual void SetUp() override {}

    virtual void TearDown() override {}

    graph<int> graph;
};

TEST_F(GraphTest, Constructor_Test) {}
