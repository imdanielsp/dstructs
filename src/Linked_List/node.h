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

#ifndef DSTRUCTS_NODE_HPP
#define DSTRUCTS_NODE_HPP

namespace DStructs {

template<class T>
class Node {
 public:
  Node();
  Node(T &data);
  Node(T &data, Node<T> *next);
  ~Node();
  T& get_data();
  void set_data(T &data);
  void set_next(Node<T> *next);
  Node<T>* next();
  bool is_next();

 private:
  T *data_;
  Node<T> *next_;
};  // Node

template <class T>
class BiNode : public Node<T> {
 public:
  BiNode();
  BiNode(T &data);
  BiNode(T &data, Node<T> *previous, Node<T> *next);
  ~BiNode();
  void set_previous(Node<T> *previous);
  Node<T>* previous();
  bool is_previous();

 private:
  Node<T> *previous_;
};  // BiNode
}  // NAMESPACE DStructs

#include "node.cc"
#endif //DSTRUCTS_NODE_HPP
