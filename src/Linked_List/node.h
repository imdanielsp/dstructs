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

#ifndef DSTRUCTS_NODE_H
#define DSTRUCTS_NODE_H

namespace DStructs {

template<class T>
class Node {
 public:
  /**
   * \brief     This is the default constructor of a Node. This constructor
   *            doesn't allocate the buffer, it is allocate through mutattors. And other
   *            constructors. The buffer and next is set to nullptr.
   * */
  Node();
  /**
   * \brief     This is an explicit constructor that takes a T& data, allocates
   * the buffer and sets next to nullptr.
   *
   * \param     const T&
   * */
  explicit Node(const T &data);
  /**
   * \brief     This constructor takes a T& data and a next node to like with
   * this node.
   *
   * \param     const T&, Node<T>
   * */
  Node(const T &data, Node<T> *next);
  /**
   * \brief     Destructor of the object. Destroy the allocated buffer.
   * */
  virtual ~Node();
  /**
   * \brief     Get the data in the current buffer and returns it.
   *
   * \returns   T&
   * */
  T& get_data() const;
  /**
   * \brief     Sets the data to the current buffer.
   *
   * \param     const T&
   * */
  void set_data(const T &data);
  /**
   * \brief     Sets the next pointer to the passed Node<T>
   *
   * \param     Node<T>*
   * */
  void set_next(Node<T>* next);
  /**
   * \brief     Returns next that is linked to this node.
   *
   * \returns   Node<T>*
   * */
  Node<T>* next() const;
  /**
   * \brief     Returns true if there is a node connected to this current node.
   *
   * \returns   bool
   * */
  bool is_next() const;

 private:
  Node<T> *next_;   //< A link to another node
  T *data_;         //< Buffer
};  // Node

template <class T>
class BiNode : public Node<T> {
 public:
  BiNode();
  explicit BiNode(const T &data);
  BiNode(const T &data, Node<T> *previous, Node<T> *next);
  virtual ~BiNode();
  void set_previous(Node<T> *previous);
  Node<T>* previous() const;
  bool is_previous() const;

 private:
  Node<T> *previous_;
};  // BiNode
}  // NAMESPACE DStructs

#include "node.cc"
#endif //DSTRUCTS_NODE_H
