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

#include "queue.h"

namespace DStructs {

template <class T>
Queue<T>::Queue() : size_(0), head_(-1) {
}

template <class T>
Queue<T>::~Queue() {

}

template <class T>
T& Queue<T>::front() const {
  if (this->head_ != -1)
    return this->buffer_.at(this->head_);
  else
    throw std::out_of_range("Nothing in front");
}

template <class T>
void Queue<T>::push(const T &data) {
  this->buffer_.push_back(data);
  this->size_++;
  this->head_++;
}

template <class T>
void Queue<T>::pop() {
  if (this->head_ >= 0) {
    this->head_--;
    this->size_--;
  }
}

template <class T>
bool Queue<T>::empty() const {
  return this->size_ == 0;
}

template <class T>
std::size_t Queue<T>::size() const {
  return this->size_;
}

} // NAMESPACE DSTRUCTS
