#include <iostream>
#include <cstdlib>
#include <chrono>

#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

inline void insert_data_to_bst(int range) {
  BST<int> bst;

  int val;

  for (int i = 0; i < range; i++) {
    val = rand() % range;
    bst.insert_data(val);
  }
}

int main() {

  return 0;
}
