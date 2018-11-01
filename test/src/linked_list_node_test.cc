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

#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>

#include "Linked_List/node.h"

class NodeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    pNode = new DStructs::Node<int>();
    pNode2 = new DStructs::Node<int>(4);
    pNode3 = new DStructs::Node<int>(kIntForTest_);
    pNode4 = new DStructs::Node<int>(8, pNode3);
    pNode5 = new DStructs::Node<int>(kIntForTest_, pNode3);
  }

  virtual void TearDown() override {
    delete pNode;
    delete pNode2;
    delete pNode3;
    delete pNode4;
    delete pNode5;
  }

  DStructs::Node<int> *pNode;
  DStructs::Node<int> *pNode2;
  DStructs::Node<int> *pNode3;
  DStructs::Node<int> *pNode4;
  DStructs::Node<int> *pNode5;

  int kIntForTest_ = 5;
};

TEST_F(NodeTest, EmptyConstructorTest) {
  EXPECT_EQ(pNode->next(), nullptr);
  EXPECT_THROW(pNode->get_data(), std::out_of_range);
  EXPECT_FALSE(pNode->is_next());
}

TEST_F(NodeTest, ConstructorWithDataTest) {
  EXPECT_EQ(pNode2->next(), nullptr);
  EXPECT_EQ(pNode2->get_data(), 4);
  EXPECT_FALSE(pNode2->is_next());

  EXPECT_EQ(pNode3->next(), nullptr);
  EXPECT_EQ(pNode3->get_data(), this->kIntForTest_);
  EXPECT_FALSE(pNode3->is_next());
}

TEST_F(NodeTest, ConstructorWithDataAndNextTest) {
  EXPECT_EQ(pNode4->next(), this->pNode3);
  EXPECT_EQ(pNode4->get_data(), 8);
  EXPECT_TRUE(pNode4->is_next());

  EXPECT_EQ(pNode5->next(), this->pNode3);
  EXPECT_EQ(pNode5->get_data(), this->kIntForTest_);
  EXPECT_TRUE(pNode5->is_next());
}

TEST_F(NodeTest, SetDataTest) {
  int n = 19;
  pNode->set_data(5);

  EXPECT_EQ(pNode->get_data(), 5);

  pNode->set_data(n);

  EXPECT_EQ(pNode->get_data(), 19);
}

TEST_F(NodeTest, GetDataTest) {
  EXPECT_THROW(pNode->get_data(), std::out_of_range);
  EXPECT_EQ(pNode2->get_data(), 4);
  EXPECT_EQ(pNode3->get_data(), kIntForTest_);
}

TEST_F(NodeTest, SetNextTest) {
  EXPECT_EQ(pNode2->get_data(), 4);

  pNode->set_next(this->pNode2);

  EXPECT_EQ(pNode->next(), pNode2);

  pNode->set_next(nullptr);

  EXPECT_EQ(pNode->next(), nullptr);
}

TEST_F(NodeTest, NextTest) {
  EXPECT_EQ(pNode->next(), nullptr);
  EXPECT_EQ(pNode4->next(), pNode3);
}

TEST_F(NodeTest, IsNextTest) {
  EXPECT_FALSE(pNode->is_next());
  EXPECT_TRUE(pNode4->is_next());
}
