#include <iostream>
#include "DStructs.h"

#define DEBUG

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

  bst.remove(40);

  int rv;
  try {
    rv = bst.search(40);
    std::cout << rv << std::endl;
  } catch (BST<int>::NoFound) {
    std::cout << "No found!" << std::endl;
  }



  return 0;
}