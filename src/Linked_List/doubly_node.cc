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
#include "doubly_node.h"

namespace DStructs {

template <class T>
DNode<T>::DNode() : data_(nullptr), next_(nullptr), prev_(nullptr) {
}

template <class T>
DNode<T>::DNode(const T& data) : next_(nullptr), prev_(nullptr) {
  this->data_ = new T;
  this->data_ = data;
}

template <class T>
DNode<T>::DNode(const DNode<T> &o) {
  this->data_ = o.data_;
  this->next_ = o.next_;
  this->prev_ = o.prev_;
}

template <class T>
DNode<T>::~DNode() {
  if (this->data_) delete  this->data_;
  this->next_ = nullptr;
  this->prev_ = nullptr;
}

template <class T>
DNode<T>& DNode<T>::operator=(const DNode<T> &o) {
  this->data_ = o.data_;
  this->next_ = o.next_;
  this->prev_ = o.prev_;
  return *this;
}

template <class T>
void DNode<T>::set_data(const T &data) {
  if (!this->data_) this->data_ = new T;
  this->data_ = data;
}

template <class T>
T& DNode<T>::get_data() const {
  if (!this->data_) throw std::out_of_range("No data");
  return *this->data_;
}

template <class T>
void DNode<T>::set_next(DNode<T> *node) {
  this->next_ = node;
}

template <class T>
DNode<T>* DNode<T>::next() const {
  return this->next_;
}

template <class T>
void DNode<T>::set_prev(DNode<T> *node) {
  this->prev_ = node;
}

template <class T>
DNode<T>* DNode<T>::prev() const {
  return this->prev_;
}

template <class T>
bool DNode<T>::is_next() const {
  return this->next_ != nullptr;
}

template <class T>
bool DNode<T>::is_prev() const {
  return this->prev_ != nullptr;
}
}
