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
#ifndef DSTRUCTS_AVL_NODE_H
#define DSTRUCTS_AVL_NODE_H

namespace DStructs {

// Forward declaration of the AVLTree class
template<class T>
class AVLTree;

template<class T>
class AVLNode {
  friend class AVLTree<T>;
 public:
  /**
   * \brief     This is an explicit constructor of the node that takes the data.
   *
   * \param     const T&
   * */
  explicit AVLNode(const T &data);
  /**
   * \brief     This constructor takes the left and the right node and also
   * the data that the node will contain.
   *
   * \param     AVLNode&, const T&, AVLNode&
   * */
  AVLNode(AVLNode &left, const T &data, AVLNode &right);
  /**
   * \brief     Data getter
   *
   * \return    const T&
   * */
  const T &get_data() const;
 private:
  unsigned char height_;
  AVLNode<T> *left_;
  T data_;
  AVLNode<T> *right_;
};

} // DSTRUCTS NAMESPACE

#include "avl_node.cc"

#endif //DSTRUCTS_AVL_NODE_H
