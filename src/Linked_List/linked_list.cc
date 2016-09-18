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
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <stdexcept>

#include "linked_list.h"
#include "node.h"

namespace DStructs {

template <class T>
LinkedList<T>::LinkedList() {
  this->front_ = nullptr;
  this->size_ = 0;
}

template <class T>
LinkedList<T>::LinkedList(std::size_t size) {
  this->size_ = size;
  Node<T> *next = this->front_;
  for (int i = 0; i < size; i++) {
    next = new Node<T>();
    next->set_data(nullptr);
    next = next->next();
  }
  next->set_next(nullptr);
}

template <class T>
LinkedList<T>::LinkedList(std::size_t size, T &data) {
  this->size_ = size;
  Node<T> *next = this->front_;
  for (int i = 0; i < size; i++) {
    next = new Node<T>();
    next->set_data(data);
    next = next->next();
  }
  next->set_next(nullptr);
}

template <class T>
LinkedList<T>::~LinkedList() {
  Node<T> *next = this->front_;
  Node<T> *temp;
  while (next->is_next()) {
    temp = next->next();

    delete next->get_data();
    delete next;
    this->size_--;

    next = temp;
  }
  delete next;
}

template <class T>
T& LinkedList<T>::front() {
  if (this->front_) return this->front_->get_data();
  else throw std::out_of_range("There is not front data");
}

template <class T>
T& LinkedList<T>::back() {
  Node<T> *next = this->front_;
  while (next->is_next())
    next = next->next();
  return next->get_data();
}

template <class T>
void LinkedList<T>::put_front(T *data) {
  this->size_++;
  Node<T> *new_node = new Node<T>(*data);
  new_node->set_next(this->front_->next());
  this->front_ = new_node;
}

template <class T>
void LinkedList<T>::put_front(T data) {
  this->size_++;
  Node<T> *new_node = new Node<T>(data);
  new_node->set_next(this->front_->next());
  this->front_ = new_node;
}

template <class T>
void LinkedList<T>::push_back(T* data) {
  Node<T> *next = this->front_;
  while (next->is_next())
    next = next->next();
  next->set_next(new Node<T>(*data, nullptr));
}

template <class T>
void LinkedList<T>::push_back(T data) {
  Node<T> *next = this->front_;
  while (next->is_next())
    next = next->next();
  next->set_next(new Node<T>(data, nullptr));
}

template <class T>
void LinkedList<T>::put_at(std::size_t index, T* data) {}

template <class T>
void LinkedList<T>::put_at(std::size_t index, T data) {}

template <class T>
T& LinkedList<T>::at(std::size_t index) {
  if (index <= this->size_ - 1) {
    Node<T> *next = this->front();
    for (int i = 0; i < index; i++) next = next->next();
    return next->get_data();
  } else {
    throw std::out_of_range("This index is out of bound");
  }
}

template <class T>
void LinkedList<T>::pop_back() {
  Node<T> *next = this->front_;
  Node<T> *prev = nullptr;

  if (next) {
    while (next->is_next()) {
      prev = next;
      next = next->next();
    }
    delete next->get_data();
    delete next;
    prev->set_next(nullptr);
  } else return;
}

template <class T>
std::size_t LinkedList<T>::size() {
  return this->size_;
}

template <class T>
bool LinkedList<T>::empty() {
  return size_ == 0;
}

}

