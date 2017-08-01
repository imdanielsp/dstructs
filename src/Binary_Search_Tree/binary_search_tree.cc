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
#include <iostream>
#include "binary_search_tree.h"

namespace DStructs {

template <class T>
BST<T>::BST() : root_(nullptr), buffer_(nullptr) {
}

template <class T>
BST<T>::~BST() {
  if (this->buffer_ != nullptr) delete this->buffer_;
  this->destroy_(this->root_);
}

template <class T>
void BST<T>::insert_data(const T &data) {
  this->insert_data_(&root_, data);
}

template <class T>
DynamicArray<T>* BST<T>::preorder() {
  this->reset_buffer_();
  this->preorder_(this->root_);
  return this->buffer_;
}

template <class T>
DynamicArray <T> * BST<T>::inorder() {
  this->reset_buffer_();
  this->inorder_(this->root_);
  return this->buffer_;
}

template <class T>
DynamicArray<T>* BST<T>::postorder() {
  this->reset_buffer_();
  this->postorder_(this->root_);
  return this->buffer_;
}

template <class T>
void BST<T>::insert_data_(BinaryTreeNode<T> **node, const T &data) {
  if (*node == nullptr) {
    *node = new BinaryTreeNode<T>(data);
  } else if ( data < (*(node))->get_data()) {
    this->insert_data_(&((*node)->left_), data);
  } else if (data > (*node)->get_data()) {
    this->insert_data_(&((*node)->right_), data);
  }
}

template <class T>
void BST<T>::reset_buffer_() {
  if (this->buffer_ != nullptr) {
    delete this->buffer_;
    this->buffer_ = nullptr;
  }
  this->buffer_ = new DynamicArray<T>();
}

template <class T>
void BST<T>::preorder_(BinaryTreeNode<T> *node) {
  if (node == nullptr) return;
  else {
    this->buffer_->push_back(node->get_data());
    this->preorder_(node->left_);
    this->preorder_(node->right_);
  }
}

template <class T>
void BST<T>::inorder_(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    this->inorder_(node->left_);
    this->buffer_->push_back(node->get_data());
    this->inorder_(node->right_);
  }
}

template <class T>
void BST<T>::postorder_(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    this->postorder_(node->left_);
    this->postorder_(node->right_);
    this->buffer_->push_back(node->get_data());
  }
}

template <class T>
const T& BST<T>::search(const T &key) const {
  return this->search_(this->root_, key)->get_data();
}

template <class T>
const T & BST<T>::find_min() const {
  return this->find_min_(this->root_)->data_;
}

template <class T>
const T & BST<T>::find_max() const {
  return this->find_max_(this->root_)->data_;
}

template <class T>
unsigned int BST<T>::height() const {
  if (!this->root_) return 0;
  unsigned int leftHeight = this->treeExplorer_(this->root_->left_) + 1;
  unsigned int rightHeight = this->treeExplorer_(this->root_->right_) + 1;

  if (leftHeight >= rightHeight) return leftHeight;
  return rightHeight;
}

template <class T>
void BST<T>::remove(const T &key) {
  this->remove_(this->root_, key);
}

// Implementation of the NoFound exception.
template <class T>
const char* BST<T>::NoFound::what() const throw() {
  return "The key doesn't exists in the tree.";
}

// Implementation of the EmptyTree exception.
template <class T>
const char* BST<T>::EmptyTree::what() const throw() {
  return "The tree is empty.";
}

template <class T>
BinaryTreeNode<T> * BST<T>::search_(BinaryTreeNode<T> *node, const T &key) const {
  if (node != nullptr) {
    if (node->get_data() == key) {
      return node;
    } else if (key < node->get_data()) { // Going left
      return this->search_(node->left_, key);
    } else if (key > node->get_data()) { // Going right
      return this->search_(node->right_, key);
    }
  }
  throw BST::NoFound();
}

template <class T>
BinaryTreeNode<T>* BST<T>::find_min_(BinaryTreeNode<T> *node) const {
  if (node != nullptr) {
    if (node->left_ != nullptr)
      return this->find_min_(node->left_);
    else
      return node;
  } else {
    throw BST<T>::EmptyTree();
  }
}

template <class T>
BinaryTreeNode<T>* BST<T>::find_max_(BinaryTreeNode<T> *node) const {
  if (node != nullptr) {
    if (node->right_ != nullptr)
      return this->find_max_(node->right_);
    else
      return node;
  }else {
    throw BST<T>::EmptyTree();
  }
}

template <class T>
unsigned int BST<T>::treeExplorer_(BinaryTreeNode<T> *node) const {
  if (!node) return 0;
  return this->treeExplorer_(node->left_) + treeExplorer_(node->right_) + 1;
}

template <class T>
BinaryTreeNode<T>* BST<T>::remove_(BinaryTreeNode<T> *node, const T &key) {
  if (node == nullptr) {
    throw BST<T>::NoFound();
  } else {
    if (node->data_ == key) { // Find the node to remove
      BinaryTreeNode<T>* temp;

         // Node with no children
      if (node->left_ == nullptr && node->right_ == nullptr) {
        delete node;
        node = nullptr;
        return nullptr;

        // Node with left child, but no right
      } else if (node->left_ != nullptr && node->right_ == nullptr) {
        temp = node->left_;
        delete node;
        node = nullptr;
        return temp;

        // Node with right child, but no left
      } else if (node->right_ != nullptr && node->left_ == nullptr) {
        temp = node->right_;
        delete node;
        node = nullptr;
        return temp;

        // Node with both, left and right children
      } else if (node->right_ != nullptr && node->left_ != nullptr) {
        temp = this->find_max_(node->left_);
        node->data_ = temp->data_;
        node->left_ = this->remove_(node->left_, node->data_);
      }
    // Move on because the current node is not the want to remove
    } else {
      if (node->data_ < key)
        node->right_ = this->remove_(node->right_, key);
      else if (node->data_ > key)
        node->left_ = this->remove_(node->left_, key);
    }
  }
  return node;
}

template <class T>
void BST<T>::destroy_(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    this->destroy_(node->left_);
    this->destroy_(node->right_);
    delete node;
    node = nullptr;
  }
}


}

