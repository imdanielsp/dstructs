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
#include "dynamic_array.h"

namespace DStructs {

const unsigned int INITIAL_CAPACITY = 4;
const float INCREASE_FACTOR = 2.0;

template <class T>
DynamicArray<T>::DynamicArray() : capacity_(INITIAL_CAPACITY),
                                  size_(0) {
  this->buffer_ = new T[this->capacity_];
}

template <class T>
void DynamicArray<T>::push_back(const T &data) {
  this->size_++;
  if (this->size_ >= this->capacity_)
    this->increase_capacity(this->size_ * INCREASE_FACTOR);
  this->buffer_[this->size_-1] = data;
}

template <class T>
void DynamicArray<T>::increase_capacity(std::size_t new_capacity) {
  T* new_buffer = new T[new_capacity];
  for (int i = 0; i < this->size_; i++)
    new_buffer[i] = this->buffer_[i];
  delete [] this->buffer_;
  this->buffer_ = new_buffer;
  this->capacity_ = new_capacity;
}

template <class T>
T & DynamicArray<T>::at(std::size_t idx) const {
  if (idx < this->size_)
    return this->buffer_[idx];
  else throw std::out_of_range("The given index is out of range");
}

template <class T>
T& DynamicArray<T>::operator[](std::size_t idx) {
  if (idx < this->size_)
    return this->buffer_[idx];
  else throw std::out_of_range("The given index is out of range");
}

template <class T>
std::size_t DynamicArray<T>::size() const {
  return this->size_;
}

template <class T>
std::size_t DynamicArray<T>::capacity() const {
  return this->capacity_;
}
}
