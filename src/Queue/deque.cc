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
#include "deque.h"

namespace DStructs {

template <class T>
Deque<T>::Deque() : Queue<T>(), tail_(-1) {
}

template <class T>
T& Deque<T>::back() const {
  if (this->tail_ >= this->head_)
    return this->buffer_->at(this->tail_);
  else
    throw std::out_of_range("Nothing in the back");
}

template <class T>
void Deque<T>::push_front(const T& data) {
  // TODO: Improve performance of this function. This is the problem of
  // implementing a queue with an array. Pushing to front is O(n) because it
  // necessary to copy the elements from the array to another in order to put
  // the new element in the front.
  DynamicArray<T> *old_buffer = this->buffer_;
  this->buffer_ = new DynamicArray<T>();

  this->buffer_->push_back(data);  // Put new data in front

  // Copy old buffer to new buffer (Need to improve this)
  for (int i = 0; i < old_buffer->size(); ++i) {
    this->buffer_->push_back((*old_buffer)[i]);
  }

  delete old_buffer;  // Deallocate old buffer

  this->size_++;
  this->tail_++;
}

template <class T>
void Deque<T>::pop() {
  // The idea is that if the head and the tail cross each other, the queue is
  // empty, there for we throw an exception.
  // This if statement is the only differences between Queue::pop() and
  // Deque::pop().
  if (this->head_ <= this->tail_) {
    // Super.pop
    Queue<T>::pop();
  } else {
    throw std::out_of_range("Nothing to pop from the queue.");
  }
}

template <class T>
void Deque<T>::pop_back() {
  // Same idea as pop. If the head and the tail cross each other, the queue
  // is empty, there for we throw an exception. Notice that the tail must
  // always but grater or equal to the head in other to pop front the back or
  // front.
  if (this->tail_ >= this->head_) {
    this->size_--;
    this->tail_--;
  } else {
    throw std::out_of_range("Nothing to pop from the back.");
  }
}

}
