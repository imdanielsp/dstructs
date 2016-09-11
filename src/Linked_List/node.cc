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

#include <exception>

#include "node.h"

namespace DStructs {

template <typename T>
Node<T>::Node() {
  this->next_ = nullptr;  //< Init empty next
  this->data_ = nullptr;    //< Allocate memory for T
}

template <typename T>
Node<T>::Node(T& data) {
  this->data_ = &data;
  this->next_ = nullptr;
}

template<typename T>
Node<T>::Node(T& data, Node<T> *next) {
  this->data_ = &data;
  this->next_ = next;
}

template <typename T>
Node<T>::~Node() {
  if (this->data_ != nullptr) delete this->data_;
  if (this->next_ != nullptr) delete this->next_;
}

template <typename T>
T& Node<T>::get_data() {
  if (!data_) throw std::out_of_range("Null found");
  return *data_;
}

template <typename T>
void Node<T>::set_data(T& data) {
  this->data_ = &data;
}

template <typename T>
void Node<T>::set_next(Node<T> *next) {
  if (!next) throw std::invalid_argument("The Node is null");
  this->next_ = next;
}

template <typename T>
Node<T>* Node<T>::next() {
  if (!next_) throw std::out_of_range("Null found");
  return next_;
}

template <typename T>
bool Node<T>::is_next() {
  return this->next_ != nullptr;
}
}  // NAMESPACE DStructs
