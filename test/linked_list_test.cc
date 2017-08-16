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
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <gtest/gtest.h>

#include "../src/Linked_List/linked_list.h"

class LinkedListTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->linked_list = new DStructs::LinkedList<int>();
  }
  virtual void TearDown() override {
    delete this->linked_list;
  }

  DStructs::LinkedList<int>*  linked_list;
};

TEST_F(LinkedListTest, LinkedListTest_EmptyConstructor_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);
  EXPECT_THROW(linked_list->back(), std::out_of_range);
  EXPECT_THROW(linked_list->pop_back(), std::out_of_range);
  EXPECT_THROW((*linked_list)[0], std::out_of_range);
  EXPECT_TRUE(linked_list->empty());
  EXPECT_EQ(linked_list->size(), 0);
}

TEST_F(LinkedListTest, LinkedListTest_InitializerConstructor_Test) {
  delete linked_list;
  linked_list = nullptr;

  int val = 5;
  linked_list = new DStructs::LinkedList<int>(10, val);

  EXPECT_EQ(linked_list->size(), 10);
  EXPECT_NO_THROW(linked_list->front());
  EXPECT_EQ(linked_list->front(), val);
  EXPECT_FALSE(linked_list->empty());
  EXPECT_EQ(linked_list->back(), val);

  for (int i = 0; i < linked_list->size(); ++i) {
    EXPECT_EQ((*linked_list)[i], val);
  }
}

TEST_F(LinkedListTest, LinkedListTest_Front_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);
  linked_list->push_back(6);
  EXPECT_EQ(linked_list->front(), 6);
  linked_list->put_front(2);
  EXPECT_EQ(linked_list->front(), 2);
  linked_list->pop_back();
  linked_list->pop_back();
//  EXPECT_THROW(linked_list->get_front(), std::out_of_range);
}

TEST_F(LinkedListTest, BackTest) {
  EXPECT_THROW(linked_list->back(), std::out_of_range);

  linked_list->push_back(5);
  linked_list->push_back(9);
  linked_list->push_back(11);

  EXPECT_EQ(linked_list->back(), 11);
}

TEST_F(LinkedListTest, LinkedListTest_PutFront_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);

  int num = 10;
  linked_list->put_front(5);

  EXPECT_EQ(linked_list->front(), 5);

  linked_list->put_front(num);

  EXPECT_EQ(linked_list->front(), 10);
}

TEST_F(LinkedListTest, LinkedListTest_PushBack_Test) {
  EXPECT_THROW(linked_list->back(), std::out_of_range);

  linked_list->push_back(6);

  EXPECT_EQ(linked_list->front(), 6);

  linked_list->push_back(9);
  linked_list->push_back(12);

  EXPECT_EQ(linked_list->back(), 12);
}

TEST_F(LinkedListTest, LinkedListTest_PutAt_Test) {
  linked_list->push_back(5);
  linked_list->push_back(6);
  linked_list->push_back(7);

  // Current list: 5 -> 6 -> 7 -> NULL

  linked_list->put_at(0, 4);

  EXPECT_EQ(linked_list->front(), 4);
  EXPECT_EQ((*linked_list)[1], 5);

  // Current list: 4->5->6->7->NULL

  linked_list->put_at(2, 3);

  EXPECT_EQ((*linked_list)[2], 3);
  EXPECT_EQ((*linked_list)[3], 6);

}

TEST_F(LinkedListTest, LinkedListTest_At_Test) {
  for (int i = 0; i < 10; ++i) {
    linked_list->push_back(i);
  }

  EXPECT_NO_THROW(linked_list->at(4));
  EXPECT_EQ(linked_list->at(5), 5);
  EXPECT_EQ(linked_list->at(9), 9);
  EXPECT_EQ(linked_list->at(0), 0);
  EXPECT_THROW(linked_list->at(10), std::out_of_range);
}

TEST_F(LinkedListTest, LinkedListTest_PopBack_Test) {
  linked_list->push_back(4);
  linked_list->push_back(5);
  linked_list->push_back(6);

  // 4->5->6->null
  EXPECT_EQ(linked_list->back(), 6);
  EXPECT_EQ(linked_list->size(), 3);
  EXPECT_EQ(linked_list->front(), 4);

  linked_list->pop_back();
  // 4->5->null

  EXPECT_EQ(linked_list->back(), 5);
  EXPECT_EQ(linked_list->size(), 2);
  EXPECT_EQ(linked_list->front(), 4);

  linked_list->pop_back();
  // 4->null

  EXPECT_EQ(linked_list->back(), 4);
  EXPECT_EQ(linked_list->size(), 1);
  EXPECT_EQ(linked_list->front(), 4);

  linked_list->pop_back();
  // null

  EXPECT_EQ(linked_list->size(), 0);
  EXPECT_THROW(linked_list->back(), std::out_of_range);
  EXPECT_THROW(linked_list->front(), std::out_of_range);
}

TEST_F(LinkedListTest, LinkedListTest_PopFront_test) {
  EXPECT_THROW(linked_list->pop_front(), std::out_of_range);

  linked_list->put_front(5);
  linked_list->put_front(9);
  linked_list->put_front(1);
  linked_list->put_front(53);

  EXPECT_EQ(linked_list->front(), 53);
  linked_list->pop_front();
  EXPECT_EQ(linked_list->size(), 3);

  EXPECT_EQ(linked_list->front(), 1);
  linked_list->pop_front();
  EXPECT_EQ(linked_list->size(), 2);

  EXPECT_EQ(linked_list->front(), 9);
  linked_list->pop_front();
  EXPECT_EQ(linked_list->size(), 1);

  EXPECT_EQ(linked_list->front(), 5);
  linked_list->pop_front();
  EXPECT_EQ(linked_list->size(), 0);

  EXPECT_THROW(linked_list->pop_front(), std::out_of_range);

}

TEST_F(LinkedListTest, LinkedListTest_Size_Test) {
  EXPECT_EQ(linked_list->size(), 0);

  linked_list->push_back(4);

  EXPECT_EQ(linked_list->size(), 1);

  linked_list->push_back(4);
  linked_list->push_back(4);
  linked_list->push_back(4);
  linked_list->push_back(4);
  linked_list->push_back(4);

  EXPECT_EQ(linked_list->size(), 6);
}

TEST_F(LinkedListTest, LinkedListTest_Empty_Test) {
  EXPECT_TRUE(linked_list->empty());

  linked_list->push_back(5);

  EXPECT_FALSE(linked_list->empty());

  linked_list->push_back(5);
  linked_list->push_back(5);

  EXPECT_FALSE(linked_list->empty());

  linked_list->pop_back();

  EXPECT_FALSE(linked_list->empty());

  linked_list->pop_back();
  linked_list->pop_back();

  EXPECT_TRUE(linked_list->empty());
}

TEST_F(LinkedListTest, LinkedListTest_Erase_Test) {
  EXPECT_EQ(linked_list->size(), 0);

  linked_list->push_back(5);
  linked_list->push_back(6);
  linked_list->push_back(7);
  linked_list->push_back(8);

  EXPECT_EQ(linked_list->front(), 5);

  linked_list->erase();

  EXPECT_EQ(linked_list->size(), 0);

  EXPECT_THROW(linked_list->front(), std::out_of_range);
}

TEST_F(LinkedListTest, LinkedListTest_Remove_Test) {
  EXPECT_EQ(linked_list->size(), 0);

  linked_list->push_back(5);
  linked_list->push_back(6);
  linked_list->push_back(7);
  linked_list->push_back(8);

  EXPECT_EQ(linked_list->size(), 4);
  EXPECT_FALSE(linked_list->remove(0));
  EXPECT_EQ(linked_list->size(), 4);

  EXPECT_TRUE(linked_list->remove(7));
  EXPECT_EQ(linked_list->size(), 3);

  EXPECT_TRUE(linked_list->remove(5));
  EXPECT_EQ(linked_list->size(), 2);
  EXPECT_EQ(linked_list->front(), 6);

  EXPECT_TRUE(linked_list->remove(8));
  EXPECT_EQ(linked_list->size(), 1);

  EXPECT_TRUE(linked_list->remove(6));
  EXPECT_EQ(linked_list->size(), 0);

  EXPECT_FALSE(linked_list->remove(6));
}

TEST_F(LinkedListTest, LinkedListTest_SubscriptOperator_Test) {
  EXPECT_THROW((*linked_list)[0], std::out_of_range);
  EXPECT_THROW((*linked_list)[-1], std::out_of_range);

  linked_list->push_back(7);
  linked_list->push_back(9);

  EXPECT_EQ((*linked_list)[0], 7);
  EXPECT_EQ((*linked_list)[1], 9);

  EXPECT_THROW((*linked_list)[2], std::out_of_range);

  linked_list->pop_back();

  EXPECT_THROW((*linked_list)[1], std::out_of_range);

  EXPECT_EQ((*linked_list)[0], 7);
}
