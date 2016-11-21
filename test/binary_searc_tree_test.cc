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

#include <gtest/gtest.h>

#include "../src/Binary_Search_Tree/binary_search_tree.h"

class BinarySearchTreeTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    bst.insert_data(50);
    bst.insert_data(30);
    bst.insert_data(40);
    bst.insert_data(70);
    bst.insert_data(60);
  }

  DStructs::BST<int> bst;
  DStructs::BST<int> bstEmpty;
};

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_InsertData_Test) {
  EXPECT_NO_THROW(bst.search(70));
  EXPECT_NO_THROW(bst.search(50));
  EXPECT_EQ(bst.find_max(), 70);
  EXPECT_EQ(bst.find_min(), 30);
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_Search_Test) {
  EXPECT_NO_THROW(bst.search(40));
  EXPECT_EQ(bst.search(40), 40);
  EXPECT_THROW(bst.search(78), DStructs::BST<int>::NoFound);
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_FindMin_Test) {
  EXPECT_NO_THROW(bst.find_min());
  EXPECT_EQ(bst.find_min(), 30);

  EXPECT_THROW(bstEmpty.find_min(), DStructs::BST<int>::EmptyTree);
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_FindMax_Test) {
  EXPECT_NO_THROW(bst.find_max());
  EXPECT_EQ(bst.find_max(), 70);

  EXPECT_THROW(bstEmpty.find_max(), DStructs::BST<int>::EmptyTree);
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_RemoveTwoChildren_Test) {
  // Removal of node with two children
  EXPECT_NO_THROW(bst.search(50));
  EXPECT_NO_THROW(bst.remove(50));
  EXPECT_THROW(bst.search(50), DStructs::BST<int>::NoFound);
  EXPECT_NO_THROW(bst.search(40));
  EXPECT_NO_THROW(bst.search(30));
  EXPECT_NO_THROW(bst.search(70));
  EXPECT_NO_THROW(bst.search(60));
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_RemoveNodeOneChildLeft_Test) {
  // Removal of node with one child to left
  EXPECT_NO_THROW(bst.search(70));
  EXPECT_NO_THROW(bst.remove(70));
  EXPECT_THROW(bst.search(70), DStructs::BST<int>::NoFound);
  EXPECT_NO_THROW(bst.search(40));
  EXPECT_NO_THROW(bst.search(30));
  EXPECT_NO_THROW(bst.search(50));
  EXPECT_NO_THROW(bst.search(60));
}

TEST_F(BinarySearchTreeTest,
       BinarySearchTreeTest_RemoveNodeOneChildToRight_Test) {
  // Removal of node with one child to right
  EXPECT_NO_THROW(bst.search(30));
  EXPECT_NO_THROW(bst.remove(30));
  EXPECT_THROW(bst.search(30), DStructs::BST<int>::NoFound);
  EXPECT_NO_THROW(bst.search(40));
  EXPECT_NO_THROW(bst.search(50));
  EXPECT_NO_THROW(bst.search(70));
  EXPECT_NO_THROW(bst.search(60));
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_RemoveNodeNoChildren_Test) {
  // Removal of node with no children
  EXPECT_NO_THROW(bst.search(40));
  EXPECT_NO_THROW(bst.remove(40));
  EXPECT_THROW(bst.search(40), DStructs::BST<int>::NoFound);
  EXPECT_NO_THROW(bst.search(50));
  EXPECT_NO_THROW(bst.search(30));
  EXPECT_NO_THROW(bst.search(70));
  EXPECT_NO_THROW(bst.search(60));
}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_InOrder_Test) {
  DStructs::DynamicArray<int>* rv = bst.inorder();

  EXPECT_EQ((*rv)[0], 30);
  EXPECT_EQ((*rv)[1], 40);
  EXPECT_EQ((*rv)[2], 50);
  EXPECT_EQ((*rv)[3], 60);
  EXPECT_EQ((*rv)[4], 70);

}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_PostOrder_Test) {
  DStructs::DynamicArray<int>* rv = bst.postorder();

  EXPECT_EQ((*rv)[0], 40);
  EXPECT_EQ((*rv)[1], 30);
  EXPECT_EQ((*rv)[2], 60);
  EXPECT_EQ((*rv)[3], 70);
  EXPECT_EQ((*rv)[4], 50);

}

TEST_F(BinarySearchTreeTest, BinarySearchTreeTest_PreOrder_Test) {
  DStructs::DynamicArray<int>* rv = bst.preorder();

  EXPECT_EQ((*rv)[0], 50);
  EXPECT_EQ((*rv)[1], 30);
  EXPECT_EQ((*rv)[2], 40);
  EXPECT_EQ((*rv)[3], 70);
  EXPECT_EQ((*rv)[4], 60);

}

























