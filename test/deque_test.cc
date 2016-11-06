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
#include <string>
#include <gtest/gtest.h>

#include "../src/Queue/deque.h"

class DequeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    pDeque = new DStructs::Deque<int>();

    for (unsigned int i = 0; i < 5; i++) {
      deque.push_front(i);
    }
  }

  virtual void TearDown() override {
    delete pDeque;
  }

  DStructs::Deque<int> deque;
  DStructs::Deque<int>* pDeque;
};

TEST_F(DequeTest, DequeTest_Constructor_Test) {
  EXPECT_NO_THROW(deque.front());
  EXPECT_EQ(this->deque.front(), 4);
  EXPECT_EQ(this->deque.size(), 5);
  EXPECT_FALSE(this->deque.empty());
}

TEST_F(DequeTest, DequeTest_Back_Test) {
  EXPECT_NO_THROW(deque.back());
  EXPECT_EQ(deque.back(), 0);
  deque.pop_back();

  EXPECT_NO_THROW(deque.back());
  EXPECT_EQ(deque.back(), 1);
  deque.pop_back();

  EXPECT_NO_THROW(deque.back());
  EXPECT_EQ(deque.back(), 2);
  deque.pop();

  EXPECT_NO_THROW(deque.back());
  EXPECT_EQ(deque.back(), 2);
  EXPECT_EQ(deque.front(), 3);
  deque.pop_back();

  EXPECT_NO_THROW(deque.back());
  EXPECT_EQ(deque.back(), 3);
  EXPECT_EQ(deque.front(), 3);
  deque.pop();

  EXPECT_THROW(deque.back(), std::out_of_range);
}

TEST_F(DequeTest, DequeTest_Push_Front_Test) {
  pDeque->push_front(1);
  EXPECT_EQ(pDeque->size(), 1);
  EXPECT_EQ(pDeque->front(), 1);
  EXPECT_EQ(pDeque->back(), 1);

  pDeque->push_front(0);
  EXPECT_EQ(pDeque->size(), 2);
  EXPECT_EQ(pDeque->front(), 0);
  EXPECT_EQ(pDeque->back(), 1);

  pDeque->push_front(2);
  EXPECT_EQ(pDeque->size(), 3);
  EXPECT_EQ(pDeque->front(), 2);
  EXPECT_EQ(pDeque->back(), 1);

  pDeque->push_front(6);
  EXPECT_EQ(pDeque->size(), 4);
  EXPECT_EQ(pDeque->front(), 6);
  EXPECT_EQ(pDeque->back(), 1);
}

TEST_F(DequeTest, DequeTest_Pop_Back_Test) {
  EXPECT_EQ(deque.back(), 0);
  EXPECT_EQ(deque.size(), 5);
  deque.pop_back();

  EXPECT_EQ(deque.back(), 1);
  EXPECT_EQ(deque.size(), 4);
  deque.pop_back();

  EXPECT_EQ(deque.back(), 2);
  EXPECT_EQ(deque.size(), 3);
  deque.pop_back();

  EXPECT_EQ(deque.back(), 3);
  EXPECT_EQ(deque.size(), 2);
  deque.pop_back();

  EXPECT_EQ(deque.back(), 4);
  EXPECT_EQ(deque.size(), 1);
  deque.pop_back();

  EXPECT_EQ(deque.size(), 0);
  EXPECT_TRUE(deque.empty());
  EXPECT_THROW(deque.back(), std::out_of_range);
  EXPECT_THROW(deque.front(), std::out_of_range);
  EXPECT_THROW(deque.pop_back(), std::out_of_range);
  EXPECT_THROW(deque.pop(), std::out_of_range);
}

TEST_F(DequeTest, DequeTest_Pop_Test) {
  EXPECT_EQ(deque.front(), 4);
  EXPECT_EQ(deque.size(), 5);
  deque.pop();

  EXPECT_EQ(deque.front(), 3);
  EXPECT_EQ(deque.size(), 4);
  deque.pop();

  EXPECT_EQ(deque.front(), 2);
  EXPECT_EQ(deque.size(), 3);
  deque.pop();

  EXPECT_EQ(deque.front(), 1);
  EXPECT_EQ(deque.size(), 2);
  deque.pop();

  EXPECT_EQ(deque.front(), 0);
  EXPECT_EQ(deque.size(), 1);
  deque.pop();

  EXPECT_TRUE(deque.empty());
  EXPECT_THROW(deque.pop(), std::out_of_range);
  EXPECT_EQ(deque.size(), 0);
  EXPECT_THROW(deque.front(), std::out_of_range);
  EXPECT_THROW(deque.back(), std::out_of_range);
}


















