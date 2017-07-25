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

namespace DStructs {

template <class T>
LinkedList<T>::LinkedList() : size_(0), front_(nullptr), tail_(nullptr) {
}

template <class T>
LinkedList<T>::LinkedList(const size_t size, const T &data)
    : size_(0), front_(nullptr), tail_(nullptr) {
  for (int i = 0; i < size; i++) {
    this->put_front(data);
  }
}

template <class T>
LinkedList<T>::~LinkedList() {
  Node<T> *next = this->front_;
  Node<T> *temp;

  if (next) {
    while (next->is_next()) {
      temp = next->next();

      delete next;
      this->size_--;

      next = temp;
    }
    delete next;
  }
}

template <class T>
T& LinkedList<T>::front() const {
  if (this->front_) return this->front_->get_data();
  else throw std::out_of_range("There is not front data");
}

template <class T>
T& LinkedList<T>::back() const {
  if (this->tail_) {
    return this->tail_->get_data();
  } else {
    throw std::out_of_range("The is not back node");
  }
}

template <class T>
void LinkedList<T>::put_front(const T &data) {
  Node<T> *new_node = new Node<T>(data);
  if (this->front_ == nullptr) {
    this->front_ = new_node;
    new_node->set_next(nullptr);
    this->tail_ = this->front_;
  } else {
    new_node->set_next(this->front_);
    this->front_ = new_node;
  }
  this->size_++;
}

template <class T>
void LinkedList<T>::push_back(const T &data) {
  Node<T> *new_node = new Node<T>(data);
  new_node->set_next(nullptr);
  if (this->front_ == nullptr) {
    this->put_front(data);
  } else {
    this->tail_->set_next(new_node);
    this->tail_ = new_node;
    this->size_++;
  }
}

template <class T>
void LinkedList<T>::put_at(const size_t index, const T &data) {
  if (index == 0) {
    this->put_front(data);
  } else {
    Node<T> *new_node = new Node<T>(data);
    if (index <= this->size_) {
      Node<T> *next = this->front_;
      Node<T> *prev = this->front_;
      for (int i = 0; i < index; i++) {
        prev = next;
        next = next->next();
      }
      new_node->set_next(next);
      prev->set_next(new_node);
      this->size_++;
    } else throw std::out_of_range("Trying to put data out of bond");
  }
}

template <class T>
T& LinkedList<T>::at(const std::size_t index) const {
  if (index <= this->size_ - 1) {
    Node<T> *next = this->front_;

    for (int i = 0; i < index; i++) next = next->next();

    return next->get_data();
  } else throw std::out_of_range("This index is out of bound");
}

template <class T>
void LinkedList<T>::pop_back() {
  if (this->size_ == 0)
    throw std::out_of_range("Nothing to pop");

  if (!this->front_->is_next()) {
    delete this->front_;
    this->front_ = nullptr;

  } else if (this->front_) {
    Node<T> *current = this->front_;

    while (current->next()->next()) current = current->next();

    delete current->next();
    current->set_next(nullptr);
    this->tail_ = current;
  }
  --this->size_;
}

template <class T>
void LinkedList<T>::pop_front() {
  if (this->size() == 0)
    throw std::out_of_range("Nothing to pop");

  if (!this->front_->next()) {
    delete this->front_;
    this->front_ = nullptr;

  } else if (this->front_) {
    Node<T>* temp = this->front_;

    this->front_ = temp->next();
    delete temp;
    temp = nullptr;
  }

  this->size_--;
}

template <class T>
std::size_t LinkedList<T>::size() const {
  return this->size_;
}

template <class T>
bool LinkedList<T>::empty() const {
  return this->size_ == 0;
}

template <class T>
void LinkedList<T>::erase() {
  int list_size = size_;
  for (int i = 0; i < list_size; i++)
    this->pop_back();
}

template <class T>
T& LinkedList<T>::operator[](std::size_t index) {
  Node<T> *next = this->front_;
  if (index <= this->size_ - 1 && next != nullptr)
    for (int i = 0; i < index; i++)
      next = next->next();
  else
    throw std::out_of_range("Index is out of range");
  return next->get_data();
}
}  // NAMESPACE DStructs
