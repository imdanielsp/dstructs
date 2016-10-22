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
Deque<T>::Deque() : Queue<T>(){
}

template <class T>
T& Deque<T>::back() const {
  if (this->head_ != -1)
    return this->buffer_->at(0);
  else
    throw std::out_of_range("Nothing in front");
}

template <class T>
void Deque<T>::push_front(const T& data) {
  DynamicArray<T> *old_buffer = this->buffer_;
  this->buffer_ = new DynamicArray<T>();

  this->buffer_->push_back(data);  // Put new data in front

  // Copy old buffer to new buffer
  for (int i = 0; i < old_buffer->size(); ++i) {
    this->buffer_->push_back((*this->buffer_)[i]);
  }
  delete old_buffer;  // Deallocate old buffer

  this->size_++;
  this->head_--;
}

template <class T>
void Deque<T>::pop_back() {
  this->size_--;
}

}
