#include <gtest/gtest.h>
#include <string>
#include <sstream>

#include "Linked_List/linked_list.h"

using namespace DStructs;

class LinkedListTest : public testing::Test {
 protected:
  virtual void SetUp() override {
    this->linked_list = std::make_shared<LinkedList<int>>();
  }
  virtual void TearDown() override {
    this->linked_list.reset();
  }

  std::shared_ptr<LinkedList<int>> linked_list;
};

/* Test Empty Constructor */
TEST_F(LinkedListTest, EmptyConstructor_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);
  EXPECT_THROW(linked_list->back(), std::out_of_range);
  EXPECT_THROW(linked_list->pop_back(), std::out_of_range);
  EXPECT_THROW((*linked_list)[0], std::out_of_range);
  EXPECT_TRUE(linked_list->empty());
  EXPECT_EQ(linked_list->size(), 0);
}

TEST_F(LinkedListTest, InitializerConstructor_Test) {
  auto val = 1;
  linked_list.reset(new LinkedList<int>(10, val));

  EXPECT_EQ(linked_list->size(), 10);
  EXPECT_NO_THROW(linked_list->front());
  EXPECT_EQ(linked_list->front(), val);
  EXPECT_FALSE(linked_list->empty());
  EXPECT_EQ(linked_list->back(), val);

  for (int i = 0; i < linked_list->size(); ++i) {
    EXPECT_EQ((*linked_list)[i], val);
  }
}

TEST_F(LinkedListTest, Front_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);
  linked_list->push_back(6);
  EXPECT_EQ(linked_list->front(), 6);
  linked_list->put_front(2);
  EXPECT_EQ(linked_list->front(), 2);
  linked_list->pop_back();
  linked_list->pop_back();
//  EXPECT_THROW(linked_list->get_front(), std::out_of_range);
}

TEST_F(LinkedListTest, Back_Test) {
  EXPECT_THROW(linked_list->back(), std::out_of_range);

  linked_list->push_back(5);
  linked_list->push_back(9);
  linked_list->push_back(11);

  EXPECT_EQ(linked_list->back(), 11);
}

TEST_F(LinkedListTest, PutFront_Test) {
  EXPECT_THROW(linked_list->front(), std::out_of_range);

  int num = 10;
  linked_list->put_front(5);

  EXPECT_EQ(linked_list->front(), 5);

  linked_list->put_front(num);

  EXPECT_EQ(linked_list->front(), 10);
}

TEST_F(LinkedListTest, PushBack_Test) {
  EXPECT_THROW(linked_list->back(), std::out_of_range);

  linked_list->push_back(6);

  EXPECT_EQ(linked_list->front(), 6);

  linked_list->push_back(9);
  linked_list->push_back(12);

  EXPECT_EQ(linked_list->back(), 12);
}

TEST_F(LinkedListTest, At_Test) {
  for (int i = 0; i < 10; ++i) {
    linked_list->push_back(i);
  }

  EXPECT_THROW(linked_list->at(10), std::out_of_range);
  EXPECT_THROW(linked_list->at(-1), std::out_of_range);

  EXPECT_NO_THROW(linked_list->at(4));
  EXPECT_EQ(linked_list->at(5), 5);
  EXPECT_EQ(linked_list->at(9), 9);
  EXPECT_EQ(linked_list->at(0), 0);
}

TEST_F(LinkedListTest, PopBack_Test) {
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

TEST_F(LinkedListTest, PopFront_test) {
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

TEST_F(LinkedListTest, Size_Test) {
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

TEST_F(LinkedListTest, Empty_Test) {
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

TEST_F(LinkedListTest, Erase_Test) {
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

TEST_F(LinkedListTest, SubscriptOperator_Test) {
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

/* Test Construct Using a Initializer List */
TEST_F(LinkedListTest, InitializerList_Test) {
  LinkedList<int> list = {0, 1, 2, 3};

  EXPECT_EQ(list[0], 0);
  EXPECT_EQ(list[1], 1);
  EXPECT_EQ(list[2], 2);
  EXPECT_EQ(list[3], 3);
}

TEST_F(LinkedListTest, ForEach_Test) {
  linked_list->push_back(1);
  linked_list->push_back(2);
  linked_list->push_back(3);
  linked_list->push_back(4);

  int idx = 0;
  linked_list->forEach([&idx, this](const auto& it) {
    EXPECT_EQ(linked_list->at(idx), idx + 1);
    idx++;
  });
}

TEST_F(LinkedListTest, Fold_Test) {
  linked_list->push_back(1);
  linked_list->push_back(2);
  linked_list->push_back(3);
  linked_list->push_back(4);

  auto rv = linked_list->fold<std::string>("",
    [](const auto& acc,const auto& curr) {
      std::stringstream ss;
      ss << acc << "-" << curr;
      return ss.str();
    });

  EXPECT_EQ(rv, "-1-2-3-4");
}

TEST_F(LinkedListTest, Map_Test) {
  linked_list->push_back(1);
  linked_list->push_back(2);
  linked_list->push_back(3);
  linked_list->push_back(4);

  int idx = 0;
  auto new_list = linked_list->map<std::string>([](const auto& it) {
    return std::to_string(it);
  });

  EXPECT_EQ(new_list.size(), linked_list->size());

  EXPECT_EQ(new_list[0], std::to_string(linked_list->at(0)));
  EXPECT_EQ(new_list[1], std::to_string(linked_list->at(1)));
  EXPECT_EQ(new_list[2], std::to_string(linked_list->at(2)));
  EXPECT_EQ(new_list[3], std::to_string(linked_list->at(3)));
}

TEST_F(LinkedListTest, Filter_Test) {
  linked_list->push_back(1);
  linked_list->push_back(2);
  linked_list->push_back(3);
  linked_list->push_back(4);

  auto rv = linked_list->filter([](const auto& it) {
    return it >= 3;
  });

  EXPECT_EQ(rv.size(), 2);
  EXPECT_EQ(rv[0], 3);
  EXPECT_EQ(rv[1], 4);
}