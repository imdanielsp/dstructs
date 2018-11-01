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
 * FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

namespace DStructs {

template<class T>
DLinkedList::DLinkedList()
    : front_(nullptr), tail_(nullptr), size_(0) {
}

template <class T>
DLinkedList::~DLinkedList() {
  auto current = this->front_;

  while (current != nullptr) {
    current = current->next();
    delete current->prev();
  }

  this->front_ = nullptr;
  this->tail_ = nullptr;
  this->size_ = 0;
}

template <class T>
T& DLinkedList::get_front() const {
  if (!this->front_) throw std::out_of_range("Nothing at the front");
  return this->front_->get_data();
}

template <class T>
T& DLinkedList::get_back() const {
  if (!this->tail_) throw std::out_of_range("Nothing in the back");
  return this->tail_->get_data();
}

template <class T>
void DLinkedList::put_at(std::size_t index, const T &data) {
  auto node = this->get_node_at(index);

  auto new_node = new DNode(data, node->next(), node);
  node->set_next(new_node);

  if (new_node->is_next()) {
    auto new_next = new_node->next();
    new_next->set_prev(new_node);
  }
}

template <class T>
T& DLinkedList::get_at(std::size_t index) const {
  auto node = this->get_node_at(index);
  return node->get_data();
}

template <class T>
DNode<T> * DLinkedList::get_node_at(std::size_t index) const {
  if (this->is_out_of_index_(index))
    throw std::out_of_range("Index out of range");

  DNode<T> *curr = this->front_;
  for (int i = 0; i < index; i++, curr = curr->next());

  return curr;
}

template <class T>
bool DLinkedList::is_out_of_index_(std::size_t index) const {
  return index < 0 && index >= this->size_;
}

void DLinkedList::put_front(const T &data) {
  auto new_node = new DNode(data);
  new_node->set_prev(this->tail_);

  if (!this->front_) {
    this->front_ = new_node;
    this->tail_ = this->front_;
  } else {
    this->front_->set_prev(new_node);
    new_node->set_next(this->front_);
    this->front_ = new_node;
  }

  this->size_++;
}

void DLinkedList::push_back(const T &data) {
  auto new_node = new DNode(data);
  new_node->set_next(this->front_);

  if (!this->tail_) {
    this->tail_ = new_node;
    this->front_ = this->tail_;
  } else {
    this->tail_->set_next(new_node);
    new_node->set_prev(this->tail_);
    this->tail_ = new_node;
  }

  this->size_++;
}

}
