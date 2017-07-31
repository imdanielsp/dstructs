/*
 * Copyright (c) 2016 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */
#ifndef DSTRUCTS_LINKED_LIST_H
#define DSTRUCTS_LINKED_LIST_H

#include "node.h"

namespace DStructs {

/**
 * \brief       Singly linked lists contain nodes which have a data field as
 * well as a 'next' field, which points to the next node in line of nodes.
 * Operations that can be performed on singly linked lists include insertion,
 * deletion and traversal.
 * */
template <class T>
class LinkedList final {
 public:
  /**
   * \brief     Default constructor.
   * */
  LinkedList<T>();
  /**
   * \brief     Initialize the LinkedList with length = size
   * and assign the values of T to the each of the nodes.
   *
   * \param     std::size_t size, T& value
   * */
  LinkedList<T>(std::size_t size, const T& data);
  /**
   * \brief     Destructor
   * */
  ~LinkedList<T>();
  /**
   * \brief     Returns the front node of the list.
   *
   * \note      O(1) time.
   *
   * \returns   T&
   * */
  T& front() const;
  /**
   * \brief     Returns the last node of the list.
   *
   * \note      O(1) time.
   *
   * \returns   T&
   * */
  T& back() const;
  /**
   * \brief     Put front will insert the provided data to the front of
   * the list by append the node to the front.
   *
   * \note      O(1) time.
   *
   * \param     T& data
   * */
  void put_front(const T& data);
  /**
   * \brief     Similar to put_front, push_back will insert the provided data,
   * but in this case, to the back of the list.
   *
   * \note      O(1) time.
   *
   * \param     const T& data
   * */
  void push_back(const T& data);
  /**
   * \brief     put_at will insert passed data to the index provided if the
   * following condition is met:
   *    index < size_ - 1
   *
   * \note      Careful, this is worst-case O(n) time.
   *
   * \param     const size_t, const T& data
   * */
  void put_at(std::size_t index, const T& data);
  /**
   * \brief     Return the data in the list at index position if the following
   * condition is met:
   *    index < size_ - 1
   *
   * \note      Careful, this is worst-case O(n) time.
   *
   * \param     std::size_t index
   * */
  T& at(std::size_t index) const;
  /**
   * \brief     Removes the data at the front of the list.
   *
   * \note      O(1) time.
   * */
  void pop_front();
  /**
   * \brief     Removes the data at the end of the list.
   *
   * \note      Careful, this is constant O(n) time.
   * */
  void pop_back();
  /**
   * \brief     Returns the size of the list.
   *
   * \returns   std::size_t
   * */
  std::size_t size() const;
  /**
   * \brief     Returns true if the size of the list is 0.
   *
   * \note      Careful, this is constant O(n) time.
   *
   * \returns   bool
   * */
  bool empty() const;
  /**
   * \brief     Destroy the list and its values.
   *
   * \note      Careful, this is constant O(n) time.
   * */
  void erase();
  /**
   * \brief     Remove any given data if in the linked list.
   *
   * \note      Careful, this is worst-case O(n).
   *
   * \param     T& data
   *
   * \returns   If the data is found and removed, returns true, otherwise false.
   * */
  bool remove(const T& data);
  /**
   * \brief     Overloaded script operator.
   *
   * \param     std::size_t
   *
   * \note      Careful, this is worst-case O(n) time.
   *
   * \returns   T&
   * */
  T& operator[](std::size_t index);
 private:
  Node<T>* front_;       //< front of the linked list
  Node<T>* tail_;        //< tail of the linked list
  std::size_t size_;     //< size of the linked list
};  // LinkedList

} // NAMESPACE DStructs

#include "linked_list.cc"
#endif //DSTRUCTS_LINKED_LIST_H
