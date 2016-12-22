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
#include "avl_tree.h"


namespace DStructs {

template <class T>
AVLTree::AVLTree() : root_(nullptr) { }

template <class T>
AVLTree::~AVLTree() {
  this->destroy_(this->root_);
}

template <class T>
unsigned char AVLTree::get_height_(AVLNode<T> *node) {
  return static_cast<unsigned char>(node ? node->height_ : 0);
}

template <class T>
int AVLTree::get_balance_factor_(AVLNode<T> *node) {
  return this->get_height_(node->right_) - this->get_height_(node->left_);
}

template <class T>
void AVLTree::fix_height_(AVLNode<T> *node) {
  unsigned int  height_left = this->get_height_(node->left_),
                height_right = this->get_height_(node->right_);
  if (height_left > height_right) {
    node->height_ = static_cast<unsigned char>(height_left + 1);
  } else {
    node->height_ = static_cast<unsigned char>(height_right + 1);
  }
}

template <class T>
AVLNode<T>* AVLTree::rotate_right_(AVLNode<T> *node) {
  AVLNode<T>* temp = node->left_;
  node->left_ = temp->right_;
  temp->right_ = node;
  this->fix_height_(node);
  this->fix_height_(temp);
  return temp;
}

template <class T>
AVLNode<T>* AVLTree::rotate_left_(AVLNode<T> *node) {
  AVLNode<T>* temp = node->right_;
  node->right_ = temp->left_;
  temp->left_ = node;
  this->fix_height_(temp);
  this->fix_height_(node);
  return temp;
}
}























































































