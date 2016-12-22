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
 * copies or suAVLantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */
#ifndef DSTRUCTS_AVL_TREE_H
#define DSTRUCTS_AVL_TREE_H

#include "avl_node.h"

namespace DStructs {

template<class T>
class AVLTree {
 public:
  /**
   * \brief       Default constructor of the AVL Tree.
   * */
  AVLTree();
  /**
   * \brief       Deconstructor destroies the tree recursevely.
   * */
  ~AVLTree();
  /**
   * \brief       Insert data in the AVL recursevely where the
   * data that is less than any given node goes to the left,
   * and the data that is greater than any given node goes to
   * the right.
   *
   * \param   const T&
   * */
  void insert(const T& data);
  /**
   * \brief       Searches for a given key in the tree recursevely.
   *  This method average O(log N).
   *
   * \param       const T& key
   * \returns     const T&
   * */
  const T& search(const T& key) const;
  /**
   * \brief       Find the min key in the AVL.
   *
   * \returns     const T&
   * */
  const T& find_min() const;
  /**
   * \brief       Find the max key in the AVL.
   *
   * \returns     const T&
   * */
  const T& find_max() const;
  /**
   * \brief       Removes a node with its key of the AVL.
   *
   * \param       const T& key
   * */
  void remove(const T& key);
 private:
  AVLNode<T>* root_;  //< Root of the tree
  /**
   * \brief       Helper method to insert data. This is the method that
   * produces the recursion.
   *
   * \params      AVLNode<T>** node, const T& data
   * \return      AVLNode<T>** node
   * */
  void insert_(AVLNode<T>** node, const T& data);
  /**
   * \brief       Helper method to search for a key in the tree recursevely.
   *
   * \param       AVLNode<T>* node, const T& key
   * \returns     AVLNode<T>*
   * */
  AVLNode<T>* search_(AVLNode<T>* node, const T& key) const;
  /**
  * \brief       Helper method to find the minimum key in the tree. This
  * method produces the recursive calls.
  *
  * \param       AVLNode<T>* node
  * \returns     AVLNode<T>*
  * */
  AVLNode<T>* find_min_(AVLNode<T>* node) const;
  /**
   * \brief       Helper method to fin the maximum key in the tree. This
   * method produces the recursive calls.
   *
   * \param       AVLNode<T>* node
   * \returns     AVLNode<T>*
   * */
  AVLNode<T>* find_max(AVLNode<T>* node) const;
  /**
   * \brief       Helper method to remove a node of the tree and balance if
   * it is necessary..
   *
   * \param       AVLNode<T>* node, const T& key
   * \returns     AVLNode<T>*
   * */
  AVLNode<T>* remove_(AVLNode<T>* node, const T& key);
  /**
   * \brief       Helper method to destroy the tree in a post-order
   * traversal way.
   *
   * \param       AVLNode<T>* node
   * */
  void destroy_(AVLNode<T>* node);
  /**
   * \brief     Get the height of the node.
   *
   * \param     AVLNode<T>*
   * \returns   unsigned char
   * */
  unsigned char get_height_(AVLNode<T>* node);
  /**
   * \brief     Calculates the balance factor of the given node.
   *
   * \param     AVLNode<T>*
   * \returns   int
   * */
  int get_balance_factor_(AVLNode<T>* node);
  /**
   * \brief     Retrieves the corrext value of height field of the given node.
   *
   * \param     AVLNode<T>*
   * */
  void fix_height_(AVLNode<T>* node);
  /**
   * \brief     Right rotation method on the tree.
   *
   * \param     AVLNode<T>*
   * \return    AVLNode<T>*
   * */
  AVLNode<T>* rotate_right_(AVLNode<T>* node);
  /**
   * \brief     Left rotation method on the tree.
   *
   * \param     AVLNode<T>*
   * \return    AVLNode<T>*
   * */
  AVLNode<T>* rotate_left_(AVLNode<T>* node);
};

} // DSTRUCTS NAMESPACE
#endif //DSTRUCTS_AVL_TREE_H
