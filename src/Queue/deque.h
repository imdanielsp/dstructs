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
#ifndef DSTRUCTS_DEQUE_H
#define DSTRUCTS_DEQUE_H

#include "queue.h"

namespace DStructs {

/**
 * \brief   A linear collection that supports element insertion and removal at both ends.
 *  The name deque is short for "double ended queue" and is usually pronounced
 *  "deck". Most Deque implementations place no fixed limits on the number of
 *  elements they may contain.
 * */
template <class T>
class Deque : public Queue<T> {
 public:
  /**
   * \breif     Default constructor
   * */
  Deque();
  /**
   * \breif     Returns the element at the end of the queue. (This is one
   * difference between queue and dequeue.
   * */
  T& back() const;
  /**
   * \breief    This method allows insertion of an element in the front of
   * the queue.
   * */
  void push_front(const T& data);
  /**
   * \breif     This method remove an element from the back of the queue.
   * This is also know as deque from the back.
   * */
  void pop_back();
  /**
   * \brief     This method remove an element from the front of the queue.
   * This is implemented in the Queue<T> class, but this has a different
   * minor behavoir.
   * */
  void pop();

 protected:
  int tail_;  //< holds index of the tail <=> size-1 iff size > 0
};

}  // NAMESPACE DSTRUCTS

#include "deque.cc"
#endif //DSTRUCTS_DEQUE_H
