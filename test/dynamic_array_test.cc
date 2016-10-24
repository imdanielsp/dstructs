/* *
 * MIT License
 *
 * Copyright (c) 2016 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <gtest/gtest.h>

#include "../src/Dynamic_Array/dynamic_array.h"

class DynamicArrayTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->dynamicArray = new DStructs::DynamicArray<int>();
  }

  virtual void TearDown() override {
    delete this->dynamicArray;
  }

  DStructs::DynamicArray<int>* dynamicArray;
};

TEST_F(DynamicArrayTest, DynamicArrayTest_DefaultConstructor_Test) {
  EXPECT_EQ(dynamicArray->capacity(), 4); // Initial capacity should be 4

  EXPECT_EQ(dynamicArray->size(), 0);

  EXPECT_THROW(dynamicArray->at(0), std::out_of_range);
  EXPECT_THROW((*dynamicArray)[42], std::out_of_range);

}

TEST_F(DynamicArrayTest, DynamicArrayTest_PushBack_Test) {
  dynamicArray->push_back(4);

  EXPECT_EQ(dynamicArray->size(), 1);
  EXPECT_EQ(dynamicArray->capacity(), 4);

  dynamicArray->push_back(5);

  EXPECT_EQ(dynamicArray->size(), 2);
  EXPECT_EQ(dynamicArray->capacity(), 4);

  dynamicArray->push_back(6);

  EXPECT_EQ(dynamicArray->size(), 3);
  EXPECT_EQ(dynamicArray->capacity(), 7);

}

TEST_F(DynamicArrayTest, DynamicArrayTest_At_Test) {
  for (int i = 0; i < 10; ++i) {
    dynamicArray->push_back(i);
  }

  for (int j = 0; j < dynamicArray->size(); ++j) {
    EXPECT_EQ(dynamicArray->at(j), j);
  }

  EXPECT_THROW(dynamicArray->at(10), std::out_of_range);
  EXPECT_THROW(dynamicArray->at(-1), std::out_of_range);
}

TEST_F(DynamicArrayTest, DynamicArrayTest_Size_Test) {
  EXPECT_EQ(dynamicArray->size(), 0);
  dynamicArray->push_back(5);
  dynamicArray->push_back(5);
  dynamicArray->push_back(5);
  EXPECT_EQ(dynamicArray->size(), 3);
}

TEST_F(DynamicArrayTest, DynamicArrayTest_Capacity_Test) {
  EXPECT_EQ(dynamicArray->capacity(), 4);
  dynamicArray->push_back(5);
  dynamicArray->push_back(5);
  dynamicArray->push_back(5);
  EXPECT_EQ(dynamicArray->capacity(), 7);
}

TEST_F(DynamicArrayTest, DynamicArrayTest_SubscriptOperator_Test) {
  for (int i = 0; i < 10; ++i) {
    dynamicArray->push_back(i);
  }

  for (int j = 0; j < dynamicArray->size(); ++j) {
    EXPECT_EQ((*dynamicArray)[j], j);
  }

  EXPECT_THROW((*dynamicArray)[10], std::out_of_range);
  EXPECT_THROW((*dynamicArray)[-1], std::out_of_range);
}

TEST_F(DynamicArrayTest, DynamicArrayTest_Growth_Test) {
  EXPECT_EQ(dynamicArray->capacity(), 4);

  for (int i = 0; i < 10; ++i) {
    dynamicArray->push_back(i);
  }

  EXPECT_EQ(dynamicArray->capacity(), 21);
}











