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

#include "../src/Linked_List/linked_list.h"

class LinkedListTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    linked_list_1 = new DStructs::LinkedList<int>();
    linked_list_2 = nullptr;
    linked_list_3 = new DStructs::LinkedList<int>(10, kTestNum);
  }

  DStructs::LinkedList<int>* linked_list_1;
  DStructs::LinkedList<int>* linked_list_2;
  DStructs::LinkedList<int>* linked_list_3;
  int kTestNum = 32;
};

TEST_F(LinkedListTest, Constructors) {
  EXPECT_TRUE(this->linked_list_1->empty());
  EXPECT_EQ(this->linked_list_1->size(), 0);
  EXPECT_EQ(this->linked_list_2->size(), 10);
  EXPECT_EQ(this->linked_list_3->size(), 10);
}

//TEST_F(LinkedListTest, PutFront) {
//  int test_num = 10;
//  this->linked_list_1->put_front(4);
//  this->linked_list_1->put_front(&test_num);
//  this->linked_list_1->put_front(89);
//
//  this->linked_list_2->put_front(9);
//  this->linked_list_2->put_front(20);
//
//  EXPECT_EQ(this->linked_list_1->size(), 3);
//  EXPECT_EQ(this->linked_list_2->size(), 2);
//  EXPECT_FALSE(this->linked_list_1->empty());
//  EXPECT_FALSE(this->linked_list_2->empty());
//
//  EXPECT_EQ(this->linked_list_1->at(0), 4);
//  EXPECT_EQ(this->linked_list_1->at(0), test_num);
//  EXPECT_EQ(this->linked_list_1->at(0), 89);
//
//  EXPECT_EQ(this->linked_list_2->at(0), 9);
//  EXPECT_EQ(this->linked_list_2->at(0), 20);
//
//}

//TEST_F(LinkedListTest, PushBack) {
//  // [10][10][10][10][10][10][10][10][10][10] [6] [9]
//  //   0   1   2   3   4   5   6   7   8   9   10  11
//  this->linked_list_3->push_back(6);
//  this->linked_list_3->push_back(9);
//
//  EXPECT_EQ(this->linked_list_3->at(10), 6);
//  EXPECT_EQ(this->linked_list_3->at(11), 9);
//
//}

TEST_F(LinkedListTest, PutAt) {
  // Initial list
  // [10][10][10][10][10][10][10][10][10][10]
  //   0   1   2   3   4   5   6   7   8   9
  // Results should be:
  // [10][10][10][10][10][10][88][10][10][10] [10]
  //   0   1   2   3   4   5   6   7   8   9   10
  this->linked_list_3->put_at(5, 88);
  // Results should be:
  // [10][10][90][10][10][10][10][88][10][10][10][10]
  //   0   1   2   3   4   5   6   7   8   9  10  11
  this->linked_list_3->put_at(2, 90);

  EXPECT_EQ(this->linked_list_3->size(), 12);
  EXPECT_EQ(this->linked_list_3->at(5), 88);
  EXPECT_EQ(this->linked_list_3->at(2), 90);
}

//TEST_F(LinkedListTest, At) {
//  this->linked_list_1->push_back(4);
//  this->linked_list_1->push_back(5);
//  this->linked_list_1->push_back(6);
//  this->linked_list_1->push_back(7);
//
//  EXPECT_EQ(this->linked_list_1->at(0), 4);
//  EXPECT_EQ(this->linked_list_1->at(1), 5);
//  EXPECT_EQ(this->linked_list_1->at(2), 6);
//  EXPECT_EQ(this->linked_list_1->at(3), 7);
//
//  EXPECT_THROW(this->linked_list_1->at(5),
//               std::invalid_argument);
//}

TEST_F(LinkedListTest, PopBack) {
  this->linked_list_3->pop_back();
  this->linked_list_3->pop_back();

  EXPECT_EQ(this->linked_list_3->size(), 8);
}

TEST_F(LinkedListTest, Size) {
  EXPECT_EQ(this->linked_list_1->size(), 0);
  EXPECT_EQ(this->linked_list_2->size(), 10);
  EXPECT_EQ(this->linked_list_3->size(), 10);

  this->linked_list_3->pop_back();
  this->linked_list_3->pop_back();
  this->linked_list_3->pop_back();

  EXPECT_EQ(this->linked_list_3->size(), 7);
}

TEST_F(LinkedListTest, Empty) {
  EXPECT_TRUE(this->linked_list_1->empty());
  EXPECT_FALSE(this->linked_list_2->empty());
}

TEST_F(LinkedListTest, Clear) {
  this->linked_list_3->clear();

  for (int i = 0; i < 10; i++)
    EXPECT_EQ(this->linked_list_3->at(i), NULL);
}

TEST_F(LinkedListTest, Erase) {
  this->linked_list_3->erase();
  EXPECT_EQ(this->linked_list_3->size(), 0);
  EXPECT_EQ(this->linked_list_3->front(), NULL);
  EXPECT_EQ(this->linked_list_3->back(), NULL);
}

TEST_F(LinkedListTest, AssingmentOperator) {
  this->linked_list_1 = this->linked_list_3;
  EXPECT_EQ(this->linked_list_1->size(), 10);
  EXPECT_EQ(this->linked_list_1->front(), kTestNum);
  EXPECT_EQ(this->linked_list_1->back(), kTestNum);
}

//TEST_F(LinkedListTest, SubcriptOperator) {
//  EXPECT_EQ(this->linked_list_3[0], kTestNum);
//  EXPECT_EQ(this->linked_list_3[2], kTestNum);
//  EXPECT_EQ(this->linked_list_3[9], kTestNum);
//  EXPECT_THROW(this->linked_list_3[10],
//               std::invalid_argument);
//}
