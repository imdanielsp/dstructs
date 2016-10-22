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

#include "../src/Queue/queue.h"
#include "../src/Linked_List/linked_list.h"


class QueueTest : public testing::Test {
 protected:
  virtual void SetUp() override {

    complex_queue.push(new DStructs::LinkedList<int>());
    complex_queue.push(new DStructs::LinkedList<int>());

    for (int i = 0; i < 50; ++i) {
      queue.push(i);
    }

    complex_queue.front()->push_back(5);
  }

  DStructs::Queue<int> queue;
  DStructs::Queue< DStructs::LinkedList<int>* > complex_queue;
};

















