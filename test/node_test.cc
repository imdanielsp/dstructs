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

#include "../src/Linked_List/node.h"

class NodeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->node_1_ = new DStructs::Node<int>(this->kIntForTest_);
    this->node_2_ = new DStructs::Node<int>(this->kIntForTest_, this->node_1_);
    this->node_3_ = new DStructs::Node<int>();
    this->node_3_->set_data(kIntForTest_);
    this->no_data_node_ = new DStructs::Node<int>();
    this->node_null_ = nullptr;
  }

  DStructs::Node<int> *node_1_;
  DStructs::Node<int> *node_2_;
  DStructs::Node<int> *node_3_;
  DStructs::Node<int> *no_data_node_;
  DStructs::Node<int> *node_null_;
  int kIntForTest_ = 5;

};

TEST_F(NodeTest, Constructors) {
  EXPECT_FALSE(node_1_->is_next());
  EXPECT_TRUE(node_2_->is_next());
  EXPECT_FALSE(node_3_->is_next());
  EXPECT_THROW(no_data_node_->get_data(), std::out_of_range);
  EXPECT_EQ(node_2_->get_data(), this->kIntForTest_);
}

TEST_F(NodeTest, Data) {
  EXPECT_EQ(node_3_->get_data(), kIntForTest_);
  EXPECT_THROW(no_data_node_->get_data(), std::out_of_range);
}

TEST_F(NodeTest, Next) {
  EXPECT_NO_THROW(node_1_->set_next(node_2_));
  EXPECT_NO_THROW(node_1_->next());
  EXPECT_NO_THROW(node_1_->next()->set_next(node_null_));
  EXPECT_TRUE(node_1_->is_next());
  EXPECT_FALSE(node_3_->is_next());
}

class BiNodeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->biNode_1_ = new DStructs::BiNode<int>();
    this->biNode_2_ = new DStructs::BiNode<int>(different_value_);
    this->biNode_3_ = new DStructs::BiNode<int>(different_value_, biNode_2_, nullptr);
  }

  int different_value_ = 9;
  DStructs::BiNode<int> *biNode_1_;
  DStructs::BiNode<int> *biNode_2_;
  DStructs::BiNode<int> *biNode_3_;
};


TEST_F(BiNodeTest, Constructor) {
  EXPECT_THROW(biNode_1_->previous(), std::out_of_range);
  EXPECT_NO_THROW(biNode_3_->previous());
  EXPECT_EQ(biNode_3_->previous()->get_data(), different_value_);
}

TEST_F(BiNodeTest, Previous) {
  EXPECT_NO_THROW(this->biNode_3_->previous());
  EXPECT_THROW(this->biNode_2_->previous(), std::out_of_range);
  EXPECT_TRUE(this->biNode_3_->is_previous());
  EXPECT_FALSE(this->biNode_1_->is_previous());

  this->biNode_2_->set_previous(this->biNode_1_);
  EXPECT_NO_THROW(this->biNode_2_->previous());
  EXPECT_TRUE(this->biNode_2_->is_previous());
}
