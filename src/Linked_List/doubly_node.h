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
#ifndef DSTRUCTS_DOUBLY_NODE_H
#define DSTRUCTS_DOUBLY_NODE_H

namespace DStructs {

template<class T>
class DNode {
 public:
  DNode();

  explicit DNode(const T& data);

  DNode(const T& data, DNode<T>* next, DNode<T>* prev);

  ~DNode();

  /**
   * \breif     Make object non-copyable
   * */
  DNode(const DNode<T>& o) = delete;
  DNode<T>& operator=(const DNode<T>& o) = delete;
  /**
   * \brief     Sets the data in the node.
   *
   * \param     const T&
   * */
  void set_data(const T& data);
  /**
   * \breif     Gets the data in the node.
   *
   * \return    T&
   * */
  T& get_data() const;
  /**
   * \brief     Set the passed node to the next.
   *
   * \param     DNode<T>*
   * */
  void set_next(DNode<T>* node);
  /**
   * \brief     Get the next node.
   *
   * \return    DNode<T>*
   * */
  DNode<T>* next() const;
  /**
   * \brief     Set the passed node to the previous.
   *
   * \param     DNode<T>*
   * */
  void set_prev(DNode<T>* node);
  /**
   * \brief     Get the previous node.
   *
   * \return    DNode<T>*
   * */
  DNode<T>* prev() const;
  /**
   * \brief     Returns true if there is a next node.
   *
   * \return    bool
   * */
  bool is_next() const;
  /**
   * \brief     Returns true if there is a previous node.
   *
   * \return    bool
   * */
  bool is_prev() const;
 private:
  DNode<T>* next_; //< Next node
  DNode<T>* prev_; //< Previous node
  T* data_;       //< Data pointer
};

} // NAMESPACE DStructs

#include "doubly_node.cc"
#endif //DSTRUCTS_DOUBLY_NODE_H

























