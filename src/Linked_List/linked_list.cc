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
  LinkedList<T>::LinkedList(std::initializer_list<T> init_list)
    : size_(0), front_(nullptr), tail_(nullptr) {

    for (const auto& it : init_list)
      this->push_back(it);
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
      this->size_--;
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
  bool LinkedList<T>::remove(const T& data) {
    if (!this->front_) return false;

    if (this->front_->get_data() == data) {
      this->pop_front();
      return true;
    } else {
      Node<T>* curr = this->front_;

      while (curr && curr->next()) {
        if (curr->next()->get_data() == data) {
          Node<T>* temp = curr->next();

          curr->set_next(temp->next());
          delete temp;
          temp = nullptr;
          this->size_--;

          return true;
        }
        curr = curr->next();
      }
      return false;
    }
  }

  template <class T>
  LinkedList<T> LinkedList<T>::copy() const {
    return forEach([](auto i) {});
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

  template <class T>
  void LinkedList<T>::forEach(std::function<void(const T&)> f) const {
    for (auto i = 0; i < this->size(); i++) {
      f(this->at(i));
    }
  }

//  template <class T>
//  template <class K>
//  LinkedList<K> LinkedList<T>::map(std::function<K(const T&)> t) const {
//    LinkedList<K> list;
//    forEach([&t, &list](auto item) { list.push_back(t(item)); });
//    return list;
//  }
//
//  template <class T>
//  LinkedList<T>
//  LinkedList<T>::filter(std::function<bool(const T &)> pred) const {
//    LinkedList<T> list;
//    forEach([&list, &pred] (auto item) {
//      if (pred(item)) {
//        list.push_back(item);
//    }});
//    return list;
//  }
//
  template <class T>
  template <class K>
  K LinkedList<T>::fold(const K& initialValue,
                        std::function<K(const K&, const T&)> op) {
    K acc = initialValue;
    this->forEach([&acc, &op](auto item) {
      acc = op(acc, item);
    });
    return acc;
  }
}  // NAMESPACE DStructs
