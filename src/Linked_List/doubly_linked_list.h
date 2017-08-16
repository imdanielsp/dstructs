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
#ifndef DSTRUCTS_DOUBLY_LINKED_LIST_H
#define DSTRUCTS_DOUBLY_LINKED_LIST_H

#include <cstdio>
#include "doubly_node.h"

namespace DStructs {

template <class T>
class DLinkedList {
 public:
  DLinkedList();

  ~DLinkedList();
  /**
   * \brief     Returns the data on front of the list. If the list is empty a
   * std::out_of_range exception will be thrown.
   *
   * \returns   T&
   *
   * \note      O(1) time
   * */
  T& get_front() const;
  /**
   * \brief     Returns the data at the end of the list. If the list is empty
   * a std::out_of_range exception will be thrown.
   *
   * \returns   T&
   *
   * \note      O(1) time.
   * */
  T& get_back() const;
  /**
   * \brief     Inserts the passed data, T&, to the list given the index iff
   * index < size_ - 1
   *
   * \param     std::size_t index, const T& data
   *
   * \note      Careful, this is worst-case O(n) time.
   * */
  void put_at(std::size_t index, const T& data);
  /**
   * \brief     Returns the data at the given index. If the index is out of
   * range, a std::out_of_range exception will be thrown.
   *
   * \param     std::size_t index
   *
   * \returns   T&
   *
   * \note      Careful, this is worst-time O(n) time.
   * */
  T& get_at(std::size_t index) const;
  /**
   * \brief     Insert a T& data on front of the list.
   *
   * \param     const T& data
   *
   * \note      O(1) time
   * */
  void put_front(const T& data);
  /**
   * \brief     Append T& data to the list.
   *
   * \param     const T& data
   *
   * \note      O(1) time
   * */
  void push_back(const T& data);
  /**
   * \brief     Remove the node on front of the list. If the list is empty a
   * std::out_of_range exception will be thrown.
   *
   * \note      O(1) time.
   * */
  void pop_front();
  /**
   * \brief     Remove the node in the back of the list. If the list is empty
   * a std::out_of_range exception will be thrown.
   *
   * \note      O(1) time.
   * */
  void pop_back();
  /**
   * \breif     Returns the size of the list.
   * */
  std::size_t get_size() const noexcept;
  /**
   * \brief     Return true is the list is empty, otherwise false.
   * */
  bool is_empty() const noexcept;
  /**
   * \brief     Remove all the nodes in the list.
   *
   * \note      Careful, this is best-case, average, and worst-case O(n) time.
   * */
  void erase();
  /**
   * \brief     Remove const T& data if it exist in the list. If successful,
   * true will be returned, otherwise false.
   *
   * \param     const T& data to remove.
   *
   * \note      Careful, this is worst-case O(n) time.
   * */
  bool remove(const T& data);

 private:
  DNode<T>* get_node_at(std::size_t index) const;
  bool is_out_of_index_(std::size_t index) const noexcept;

 private:
  DNode<T>* front_;       //< get_front node of the linked list
  DNode<T>* tail_;        //< tail node of the linked list
  unsigned int size_;     //< size of the linked list
};

}

#include "doubly_linked_list.cc"
#endif //DSTRUCTS_DOUBLY_LINKED_LIST_H



















