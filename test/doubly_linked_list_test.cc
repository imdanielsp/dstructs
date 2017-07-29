/* *
 * MIT License
 *
 * Copyright (c) 2017 Daniel Santos
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

#include "../src/Linked_List/doubly_node.h"

class DNodeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->dNode = new DStructs::DNode<int>();
  }

  virtual void TearDown() override {
    delete this->dNode;
  }

  DStructs::DNode<int>* dNode;
};

TEST_F(DNodeTest, DNodeTest_Default_Constructor_Test) {
  EXPECT_THROW(this->dNode->get_data(), std::out_of_range);
  EXPECT_EQ(this->dNode->next(), nullptr);
  EXPECT_EQ(this->dNode->prev(), nullptr);
  EXPECT_FALSE(this->dNode->is_prev());
  EXPECT_FALSE(this->dNode->is_next());
}

TEST_F(DNodeTest, DNodeTest_DataConstructor_Test) {
  DStructs::DNode<int> node(4);

  EXPECT_EQ(node.get_data(), 4);
  EXPECT_EQ(node.next(), nullptr);
  EXPECT_EQ(node.prev(), nullptr);
}

TEST_F(DNodeTest, DNodeTest_SetData_Test) {
  EXPECT_THROW(this->dNode->get_data(), std::out_of_range);

  this->dNode->set_data(6);

  EXPECT_EQ(this->dNode->get_data(), 6);
  EXPECT_EQ(this->dNode->get_data(), 6);
}

TEST_F(DNodeTest, DNodeTest_GetData_Test) {
  EXPECT_THROW(this->dNode->get_data(), std::out_of_range);

  this->dNode->set_data(0);

  EXPECT_EQ(this->dNode->get_data(), 0);
}

TEST_F(DNodeTest, DNodeTest_SetNext_Test) {
  EXPECT_EQ(this->dNode->next(), nullptr);

  DStructs::DNode<int> node(4);

  this->dNode->set_next(&node);

  EXPECT_EQ(this->dNode->next()->get_data(), 4);
}

TEST_F(DNodeTest, DNodeTest_SetPrev_Test) {
  EXPECT_EQ(this->dNode->prev(), nullptr);

  DStructs::DNode<int> node(4);

  this->dNode->set_prev(&node);

  EXPECT_EQ(this->dNode->prev()->get_data(), 4);
}

TEST_F(DNodeTest, DNodeTest_IsNext_Test) {
  EXPECT_FALSE(this->dNode->is_next());

  DStructs::DNode<int> node(4);
  this->dNode->set_next(&node);

  EXPECT_TRUE(this->dNode->is_next());
}

TEST_F(DNodeTest, DNodeTest_IsPrev_Test) {
  EXPECT_FALSE(this->dNode->is_prev());

  DStructs::DNode<int> node(4);
  this->dNode->set_prev(&node);

  EXPECT_TRUE(this->dNode->is_prev());
}
