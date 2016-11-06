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

#include <string>
#include <gtest/gtest.h>

#include "../src/Queue/queue.h"
#include "../src/Linked_List/linked_list.h"


class QueueTest : public testing::Test {
 protected:
  virtual void SetUp() override {

    // Push 50 objects to the queue
    for (int i = 0; i < 50; ++i) {
      queue.push(i);
    }

    /*
     * This data structure should be something like:
      Queue< LinkedList<int> >
      __________________________________________
       ++++++++++++  |  ++++++++++++++++++++
      + 7 -> 6 -> 5+ | + 11 -> 10 ->10 -> 11  +
       ++++++++++++  |  ++++++++++++++++++++
      _______________|__________________________

     * */

    complex_queue.push(new DStructs::LinkedList<int>());
    complex_queue.front()->push_back(5);
    complex_queue.front()->push_back(6);
    complex_queue.front()->push_back(7);

    complex_queue.push(new DStructs::LinkedList<int>());
    complex_queue.front()->push_back(8);
    complex_queue.front()->push_back(9);
    complex_queue.front()->push_back(10);
    complex_queue.front()->push_back(11);

  }

  DStructs::Queue<int> queue;
  DStructs::Queue< DStructs::LinkedList<int>* > complex_queue;
};

TEST_F(QueueTest, Front) {
  for (int i = 0; queue.size() != 0; i++) {
    EXPECT_EQ(queue.front(), i);
    queue.pop();
  }

  EXPECT_EQ(complex_queue.front()->front(), 5);
  EXPECT_EQ(complex_queue.front()->at(1), 6);
  complex_queue.pop();

  EXPECT_EQ(complex_queue.size(), 1);

  complex_queue.pop();
}

TEST_F(QueueTest, QueueTest_Push_Test) {
  DStructs::Queue<std::string> str_queue;

  str_queue.push("C");
  str_queue.push("C++");
  str_queue.push("Python");
  str_queue.push("Java");

  EXPECT_EQ(str_queue.size(), 4);
  EXPECT_EQ(str_queue.front(), "C");

  str_queue.pop();

  EXPECT_EQ(str_queue.front(), "C++");

  str_queue.pop();

  EXPECT_EQ(str_queue.front(), "Python");

  str_queue.pop();
  str_queue.pop();

  EXPECT_THROW(str_queue.front(), std::out_of_range);
}

TEST_F(QueueTest, QueueTest_Pop_Test) {
  EXPECT_EQ(this->queue.size(), 50);
  EXPECT_EQ(this->queue.front(), 0);

  this->queue.pop();

  EXPECT_EQ(this->queue.size(), 49);
  EXPECT_EQ(this->queue.front(), 1);

  DStructs::Queue<int> q;

  q.push(5);

  q.pop();

  EXPECT_THROW(q.pop(), std::out_of_range);
}

TEST_F(QueueTest, QueueTest_Empty_Test) {
  DStructs::Queue<int> queue1;
  EXPECT_FALSE(this->queue.empty());

  EXPECT_TRUE(queue1.empty());
}

TEST_F(QueueTest, QueueTest_Size_Test) {
  EXPECT_EQ(this->queue.size(), 50);
  this->queue.pop();

  EXPECT_EQ(this->queue.size(), 49);
}







