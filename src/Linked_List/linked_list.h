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
#ifndef DSTRUCTS_LINKED_LIST_H
#define DSTRUCTS_LINKED_LIST_H

#include "node.h"

namespace DStructs {

template <class T>
class LinkedList {
 public:
  /*
   * Brief:   Default constructor that allocate the front node.
   * */
  LinkedList<T>();
  /*
   * Brief:   Initialize the LinkedList with a length of size.
   * Param:   unsigned int size
   * */
  explicit LinkedList<T>(size_t size);
  /*
   * Brief:   Initialize the LinkedList with length = size
   *          and assign the values of T to the each of the nodes.
   * Param:   unsigned int size, T* value
   * */
  LinkedList<T>(size_t size, T* data);
  /*
   * Brief:   De constructor
   * */
  ~LinkedList<T>();
  /*
   * Brief:   Put front will insert the provided data to the front of
   *          the list by append the node to the front.
   * Param:   T* data
   * */
  void put_front(T* data);
  /*
   * Brief:   Similar to put_front, push_back will insert the provided data,
   *          but in this case, to the back of the list.
   * Param:   T* data
   * */
  void push_back(T* data);
  /*
   * Brief:   put_at will insert passed data to the index provided if the following
   *          condition is met:
   *                index < size_ - 1
   * Param:   size_t index, T* data
   * */
  void put_at(size_t index, T* data);
  /*
   * Brief:   Return the data in the list at index position if the following condition
   *          is met:
   *                index < size_ - 1
   * Param:   size_t index
   * */
  T* at(size_t index);
  /*
   * Brief:   Returns and delete the last value of the list.
   * Returns: T*
   * */
  T* pop_back();
  /*
   * Brief:   Returns the size of the list.
   * Returns: size_t
   * */
  size_t size();
  /*
   * Brief:   Returns true if the size of the list is 0.
   * Returns: bool
   * */
  bool empty();
  /*
   * Brief:   Clear all the values of the list, assigning it to
   *          a null pointer.
   * */
  void clear();
  /*
   * Brief:   Destroy the list and its values.
   * */
  void erase();
 private:
  /*
   * Brief:   Returns the front node of the list.
   * Returns: Node<T>*
   * */
  Node<T>* get_front();
  /*
   * Brief:   Returns the last node of the list.
   * Returns: Node<T>*
   * */
  Node<T>* get_last();
  Node<T>* front_;  //< front of the linked list
  size_t size_;     //< size of the linked list
};

} // NAMESPACE DStructs

#endif //DSTRUCTS_LINKED_LIST_H
