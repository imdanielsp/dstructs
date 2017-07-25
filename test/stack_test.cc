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

#include "../src/Stack/stack.h"

class StackTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->stack = new DStructs::Stack<int>();
  }

  virtual void TearDown() override {
    delete this->stack;
  }

  DStructs::Stack<int>* stack;
};


TEST_F(StackTest, StackTest_Constructor_Test) {
  EXPECT_EQ(stack->empty(), true);
  EXPECT_EQ(stack->size(), 0);
  EXPECT_THROW(stack->pop(), std::out_of_range);
  EXPECT_THROW(stack->top(), std::out_of_range);
}

TEST_F(StackTest, StackTest_Push_Test) {
  stack->push(5);
  EXPECT_EQ(stack->top(), 5);
  EXPECT_EQ(stack->size(), 1);

  stack->push(6);
  stack->push(0);
  stack->push(12);
  stack->push(6123);

  EXPECT_EQ(stack->top(), 6123);
  EXPECT_EQ(stack->size(), 5);
}

TEST_F(StackTest, StackTest_Pop_Test) {
  stack->push(6);
  stack->push(0);
  stack->push(12);
  stack->push(6123);

  stack->pop();
  EXPECT_EQ(stack->top(), 12);

  stack->pop();
  EXPECT_EQ(stack->top(), 0);

  stack->pop();
  EXPECT_EQ(stack->top(), 6);

  stack->pop();
  EXPECT_EQ(stack->size(), 0);
  EXPECT_EQ(stack->empty(), true);

  EXPECT_THROW(stack->pop(), std::out_of_range);
}

TEST_F(StackTest, StackTest_Top_Test) {
  EXPECT_THROW(stack->top(), std::out_of_range);

  stack->push(6);
  stack->push(0);
  stack->push(12);
  stack->push(6123);

  EXPECT_EQ(stack->top(), 6123);

  stack->pop();
  stack->pop();
  stack->pop();

  EXPECT_EQ(stack->top(), 6);

  stack->pop();

  EXPECT_THROW(stack->top(), std::out_of_range);
}

TEST_F(StackTest, StackTest_Size_Test) {
  EXPECT_EQ(stack->size(), 0);

  stack->push(6);
  EXPECT_EQ(stack->size(), 1);

  stack->push(0);
  EXPECT_EQ(stack->size(), 2);

  stack->push(12);
  EXPECT_EQ(stack->size(), 3);

  stack->pop();
  EXPECT_EQ(stack->size(), 2);
}

TEST_F(StackTest, StackTest_Empty_Test) {
  EXPECT_EQ(stack->empty(), true);

  stack->push(6);
  EXPECT_EQ(stack->empty(), false);

  stack->push(0);
  EXPECT_EQ(stack->empty(), false);

  stack->pop();
  EXPECT_EQ(stack->empty(), false);

  stack->pop();
  EXPECT_EQ(stack->empty(), true);
}
