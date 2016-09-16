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
    linked_list_2 = new DStructs::LinkedList<int>(10);
    linked_list_3 = new DStructs::LinkedList<int>(10, kTestNum);
  }
 private:
  DStructs::LinkedList* linked_list_1;
  DStructs::LinkedList* linked_list_2;
  DStructs::LinkedList* linked_list_3;
  int kTestNum = 32;
};

TEST_F(LinkedListTest, Constructors) {

}

TEST_F(LinkedListTest, PutFront) {

}

TEST_F(LinkedListTest, PushBack) {

}

TEST_F(LinkedListTest, PutAt) {

}

TEST_F(LinkedListTest, At) {

}

TEST_F(LinkedListTest, PopBack) {

}

TEST_F(LinkedListTest, Size) {

}

TEST_F(LinkedListTest, Empty) {

}

TEST_F(LinkedListTest, Clear) {

}

TEST_F(LinkedListTest, Erase) {

}

TEST_F(LinkedListTest, AssingmentOperator) {

}

TEST_F(LinkedListTest, SubcriptOperator) {

}

















