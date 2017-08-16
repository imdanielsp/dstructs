#include <iostream>
#include <cstdlib>
#include <chrono>

#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

inline void insert_data_to_bst(int range) {
  BST<int> bst;

  int val;

  srand(time(NULL));

//  for (int i = 0; i < range; i++) {
//    val = rand() % range;
//    bst.insert_data(val);
//  }

  bst.insert_data(7);
  bst.insert_data(3);
  bst.insert_data(5);
  bst.insert_data(2);
  bst.insert_data(1);
  bst.insert_data(4);
  bst.insert_data(6);
  bst.insert_data(7);

  std::cout << bst.height() << std::endl;

}

int main() {

  insert_data_to_bst(100);

  return 0;
}
