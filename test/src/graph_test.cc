#include <gtest/gtest.h>

#include "Graph/graph.h"

using namespace DStructs;

class GraphTest : public testing::Test {
protected:
  virtual void SetUp() override {

  }

  virtual void TearDown() override {

  }

  Graph<int> graph;
};

TEST_F(GraphTest, Constructor_Test) {

}
