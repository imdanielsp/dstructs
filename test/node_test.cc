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
#include <exception>
#include <gtest/gtest.h>

#include "../src/Linked_List/node.h"

int kIntTest = 5;  //<

TEST(NodeTest, Constructors) {

  DStructs::Node<int> *node_1 = new DStructs::Node<int>(kIntTest);
  DStructs::Node<int> *node_2 = new DStructs::Node<int>(kIntTest, node_1);
  DStructs::Node<int> *node_3 = new DStructs::Node<int>();

  EXPECT_FALSE(node_1->is_next());
  EXPECT_TRUE(node_2->is_next());
  EXPECT_FALSE(node_3->is_next());
  EXPECT_THROW(node_3->get_data(), std::out_of_range);
  EXPECT_EQ(node_2->get_data(), kIntTest);
}

TEST(NodeTest, Data) {

  DStructs::Node<int> *node = new DStructs::Node<int>();
  DStructs::Node<int> *node_2 = new DStructs::Node<int>();

  node->set_data(kIntTest);

  EXPECT_EQ(node->get_data(), kIntTest);
  EXPECT_THROW(node_2->get_data(), std::out_of_range);

}

TEST(NodeTest, Next) {
  DStructs::Node<int> *node_1 = new DStructs::Node<int>();
  DStructs::Node<int> *node_2 = new DStructs::Node<int>(kIntTest);
  DStructs::Node<int> *node_null = nullptr;

  EXPECT_NO_THROW(node_1->set_next(node_2));
  EXPECT_NO_THROW(node_1->next());
  EXPECT_THROW(node_1->next()->set_next(node_null), std::invalid_argument);
  EXPECT_TRUE(node_1->is_next());
  EXPECT_FALSE(node_2->is_next());
}
