//
// Created by Daniel Santos on 8/6/18.
//

#include <gtest/gtest.h>
#include "Heap/heap.h"

class HeapTest : public  testing::Test {
 protected:
  virtual void SetUp() override {

  }

  DStructs::MaxHeap<int> maxHeap{10, 20, 30};
  DStructs::MinHeap<int> minHeap{30, 20, 10};
};

TEST_F(HeapTest,HeapTest_InsertData_Test) {
 EXPECT_EQ(maxHeap.top(), 30);

 EXPECT_EQ(minHeap.top(), 10);
}