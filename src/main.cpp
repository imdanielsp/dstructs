#include <iostream>
#include "DStructs.h"

#define DEBUG

using namespace DStructs;

int main() {

  BST<int> bst;

  bst.insert_data(27);
  bst.insert_data(13);
  bst.insert_data(6);
  bst.insert_data(17);
  bst.insert_data(42);
  bst.insert_data(33);
  bst.insert_data(48);
  bst.insert_data(52);

  int rv;
  rv = bst.find_max();
  std::cout << rv << std::endl;

  return 0;
}