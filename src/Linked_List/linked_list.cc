#include <stdexcept>
#include "linked_list.h"

namespace DStructs {

  template <class T>
  LinkedList<T>::LinkedList() : _size(0), _front(nullptr), _tail(nullptr)
  {}

  template <class T>
  LinkedList<T>::LinkedList(const std::size_t size, const T &data)
      : _size(0), _front(nullptr), _tail(nullptr) {
    for (int i = 0; i < size; i++) {
      this->push_back(data);
    }
  }

  template <class T>
  LinkedList<T>::LinkedList(std::initializer_list<T> init_list)
    : _size(0), _front(nullptr), _tail(nullptr) {
    for (const auto& it : init_list)
      this->push_back(it);
  }

  template <class T>
  LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    ReadLock lock(other._mtx);

    other.forEach([this](const auto& it) {
      this->push_back(it);
    });
  }

  template <class T>
  LinkedList<T>::~LinkedList() {
    WriteLock lock(this->_mtx);

    auto curr = std::move(this->_front);
    while (curr) {
      auto temp = std::move(curr->_next);
      curr.reset();
      curr = std::move(temp);
    }
    this->_tail.reset();
    this->_size = 0;
  }

  template <class T>
  T& LinkedList<T>::front() const {
    ReadLock lock(_mtx);

    if (this->_front)
      return this->_front->_value;
    else throw std::out_of_range("There is not front data");
  }

  template <class T>
  T& LinkedList<T>::back() const {
    ReadLock lock(_mtx);

    if (this->_tail)
      return this->_tail->_value;
    else throw std::out_of_range("The is not back node");
  }

  template <class T>
  void LinkedList<T>::put_front(const T &data) {
    WriteLock lock(this->_mtx);

    if (!this->_front) {
      this->_front = make_node<T>(data);
      this->_tail = this->_front;
    } else {
      this->_front = make_node<T>(data, this->_front);
    }
    this->_size++;
  }

  template <class T>
  void LinkedList<T>::push_back(const T &data) {
    if (!this->_front) {
      this->put_front(data);
    } else {
      WriteLock lock(this->_mtx);

      this->_tail->_next = make_node<T>(data);
      this->_tail = this->_tail->_next;
      this->_size++;
    }
  }

  template <class T>
  T& LinkedList<T>::at(const std::size_t index) const {
    ReadLock lock(this->_mtx);

    if (index < 0 || index >= this->_size)
      throw std::out_of_range("out of bound index");

    auto curr = this->_front;
    for (std::size_t i = 0; i < index; i++) curr = curr->_next;

    return curr->_value;
  }

  template <class T>
  void LinkedList<T>::pop_back() {
    WriteLock lock(this->_mtx);

    if (this->_size == 0)
      throw std::out_of_range("list is empty");

    if (this->_front == this->_tail) {
      this->_front.reset();
      this->_tail.reset();
    } else {
      /* Finds the node before the tail */
      auto curr = this->_front;
      while (curr->_next != this->_tail) curr = curr->_next;

      curr->_next.reset();
      this->_tail = curr;
    }

    this->_size--;
  }

  template <class T>
  void LinkedList<T>::pop_front() {
    if (this->_size == 0)
      throw std::out_of_range("list is empty");

    if (this->_front == this->_tail) {
      this->pop_back();
    } else {
      WriteLock lock(this->_mtx);

      auto temp = std::move(this->_front->_next);
      this->_front.reset();
      this->_front = std::move(temp);
      this->_size--;
    }
  }

  template <class T>
  std::size_t LinkedList<T>::size() const {
    ReadLock lock(this->_mtx);

    return this->_size;
  }

  template <class T>
  bool LinkedList<T>::empty() const {
    ReadLock lock(this->_mtx);

    return this->_size == 0;
  }

  template <class T>
  void LinkedList<T>::erase() {
    std::size_t list_size = _size;
    for (std::size_t i = 0; i < list_size; i++)
      this->pop_front();
  }

  template <class T>
  T& LinkedList<T>::operator[](std::size_t index) {
    return this->at(index);
  }

  template <class T>
  void LinkedList<T>::forEach(std::function<void(const T&)> f) const {
    for (auto i = 0; i < this->size(); i++) {
      f(this->at(i));
    }
  }

  template <class T>
  template <class K>
  LinkedList<K> LinkedList<T>::map(std::function<K(const T&)> f) const {
    LinkedList<K> list;
    forEach([&f, &list](auto item) { list.push_back(f(item)); });
    return list;
  }

  template <class T>
  LinkedList<T> LinkedList<T>::filter(
      std::function<bool(const T &)> pred) const {
    LinkedList<T> list;
    forEach([&list, &pred] (auto item) {
      if (pred(item)) {
        list.push_back(item);
    }});
    return list;
  }

  template <class T>
  template <class K>
  K LinkedList<T>::fold(const K& initialValue,
      std::function<K(const K&, const T&)> op) const {
    K acc = initialValue;
    this->forEach([&acc, &op](const auto& item) {
      acc = op(acc, item);
    });
    return acc;
  }
}  // NAMESPACE DStructs
