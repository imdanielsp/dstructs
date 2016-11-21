#include <iostream>
#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

int main() {

  BST<int> bst;
/*
 *           50
           /     \
          30     70
            \    /
            40  60
 *
 * */
  bst.insert_data(50);
  bst.insert_data(30);
  bst.insert_data(40);
  bst.insert_data(70);
  bst.insert_data(60);

  DynamicArray<int>* rv = bst.postorder();

  for (int i = 0; i < rv->size(); i++)
    std::cout << (*rv)[i] << std::endl;
    
  return 0;
}
