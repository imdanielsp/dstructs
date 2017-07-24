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
#ifndef DSTRUCTS_STACK_H
#define DSTRUCTS_STACK_H

#include "../Linked_List/linked_list.h"

namespace DStructs {

/**
 *  \breif  Stack is a fundamental container data structure that handles
 *  elements as first in last out. This stack will support basic operation,
 *  such as push (insertion) and pop (deletion). For the buffer, we will be
 *  using a linked list that ensures O(1) time for insertion and deletion.
 * */
template<class T>
class Stack {
 public:
  /**
   * \brief     Default constructor
   * */
  Stack();
  /**
   * \breif     Destructor
   * */
  ~Stack();
  /**
   * \brief     This method inserts the data to the stack in O(1) time.
   *
   * \param     T& data
   * */
  void push(const T& data);
  /**
   * \brief     This methods removes the data from the stack in O(1) time.
   *
   * \returns   T&
   * */
  T& pop();
  /**
   * \brief     Returns the top element in the stack in O(1) time.
   *
   * \returns   T&
   * */
  T& top() const;
  /**
   * \brief     Returns the current size of the stack.
   *
   * \returns   size_t
   * */
  size_t size() const;
  /**
   * \brief     Returns true if the stack has no elements, otherwise returns
   * false.
   *
   * \returns   bool
   * */
  bool empty() const;

  /**
   * \brief     Deleted copy-constructor
   * */
  Stack(const Stack<T>&) = delete;
  /**
   * \brief     Deleted assignment operator
   * */
  Stack<T>& operator=(const Stack<T>&) = delete;
 private:
  LinkedList<T> buffer_;  //< Buffer for the stack
};
}

#include "stack.cc"
#endif //DSTRUCTS_STACK_H
