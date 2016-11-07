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
#ifndef DSTRUCTS_BINARY_SEARCH_TREE_H
#define DSTRUCTS_BINARY_SEARCH_TREE_H

#include <cstdio>
#include "binary_tree_node.h"

namespace DStructs {

  template <class T>
  class BST {
   public:
    /**
     * \brief   Default constructor of the BST.
     * */
    BST();
    /**
     * \brief   Deconstructor destroies the tree recursevely.
     * */
    ~BST();
    /**
     * \brief       Insert data in the BST recursevely where the
     * data that is less than any given node goes to the left,
     * and the data that is greater than any given node goes to
     * the right.
     *
     * \param   const T&
     * */
    void insert_data(const T& data);
    /**
     * \brief       Prints the tree in pre-order traversal, i.e.,
     * it prints the data first, then it goes left and then right.
     * In other words, this visit the node first and then go to left.
     * */
    void preorder() const;
    /**
     * \brief       Prints the tree in in-order traversal, i.e.,
     * it first go to the left, then prints the data, and then
     * goes right. In other words, this visit the node before
     * moving right.
     * */
    void inorder() const;
    /**
     * \brief       Prints the tree in post-order traversal, i.e.,
     * it first go left, then it goes right and after print the
     * data. In other words, this visit the node last.
     * */
    void postorder() const;
    /**
     * \brief       Searches for a given key in the tree recursevely.
     *  This method average O(log N).
     *
     * \param       const T& key
     * \returns     const T&
     * */
    const T& search(const T &key) const;
    /**
     * \brief       Find the min key in the BST.
     *
     * \returns     const T&
     * */
    const T& find_min() const;
    /**
     * \brief       Find the max key in the BST.
     *
     * \returns     const T&
     * */
    const T& find_max() const;
    /**
     * \brief       Removes a node with its key of the BST.
     *
     * \param       const T& key
     * */
    void remove(const T& key);

    /**
     * \brief       This is an helper exception that is thrown when the
     * BST can't find a key, i.e., the key doesn't exists.
     * */
    class NoFound : public std::exception {
     public:
      virtual const char* what() const throw();
    };

    /**
     * \brief       This is an helper exception that is thrown where the
     * BST is empty and the is attempt to find, or search.
     * */
    class EmptyTree : public std::exception{
     public:
      virtual const char* what() const throw();
    };

   private:
    BinaryTreeNode<T>* root_ ;  //< Root node of the BST
    /**
     * \brief       Helper method to insert data. This is the method that
     * produces the recursion.
     *
     * \params      BinaryTreeNode<T>** node, const T& data
     * \return      BinaryTreeNode<T>** node
     * */
    void insert_data_(BinaryTreeNode<T>** node, const T& data);
    /**
     * \brief       Helper method to print the tree in pre-order traversal.
     *
     * \param       BinaryTreeNode<T>* node
     * */
    void preorder_(BinaryTreeNode<T>* node) const;
    /**
     * \brief       Helper method to print the tree in in-order traversal.
     *
     * \param       BinaryTreeNode<T>* node
     * */
    void inorder_(BinaryTreeNode<T>* node) const;
    /**
     * \brief       Helper method to print the tree in port-order traversal.
     *
     * \param       BinaryTreeNode<T>* node
     * */
    void postorder_(BinaryTreeNode<T>* node) const;
    /**
     * \brief       Helper method to search for a key in the tree recursevely.
     *
     * \param       BinaryTreeNode<T>* node, const T& key
     * \returns     BinaryTreeNode<T>*
     * */
    BinaryTreeNode<T>* search_(BinaryTreeNode<T>*   node, const T& key) const;
    /**
     * \brief       Helper method to find the minimum key in the tree. This
     * method produces the recursive calls.
     *
     * \param       BinaryTreeNode<T>* node
     * \returns     BinaryTreeNode<T>*
     * */
    BinaryTreeNode<T>* find_min_(BinaryTreeNode<T>* node) const;
    /**
     * \brief       Helper method to fin the maximum key in the tree. This
     * method produces the recursive calls.
     *
     * \param       BinaryTreeNode<T>* node
     * \returns     BinaryTreeNode<T>*
     * */
    BinaryTreeNode<T>* find_max_(BinaryTreeNode<T>* node) const;
    /**
     * \brief       Helper method to remove a node of the tree and balance if
     * it is necessary..
     *
     * \param       BinaryTreeNode<T>* node, const T& key
     * \returns     BinaryTreeNode<T>*
     * */
    BinaryTreeNode<T>* remove_(BinaryTreeNode<T>* node, const T& key);
    /**
     * \brief       Helper method to destroy the tree in a post-order
     * traversal way.
     *
     * \param       BinaryTreeNode<T>* node
     * */
    void destroy_(BinaryTreeNode<T>* node);

  }; // BST class

} // DSTRUCTS NAMESPACE

#include "binary_search_tree.cc"

#endif //DSTRUCTS_BINARY_SEARCH_TREE_H





















