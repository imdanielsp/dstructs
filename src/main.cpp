#include <iostream>
#include "DStructs.h"

#define DEBUG

using namespace DStructs;

int main() {

  BST<int> bst;
/*
 *           50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
 *
 * */
  bst.insert_data(50);
  bst.insert_data(30);
  bst.insert_data(20);
  bst.insert_data(40);
  bst.insert_data(70);
  bst.insert_data(60);
  bst.insert_data(80);

  int rv;
  rv = bst.search(60);
  std::cout << rv << std::endl;

  bst.remove(20);
  bst.remove(40);
  bst.remove(60);
  bst.remove(80);

  try {
    rv = bst.search(60);
    std::cout << rv << std::endl;
    rv = bst.search(50);
  } catch (BST<int>::NoFound) {
    std::cout << "No found!" << std::endl;
  }



  return 0;
}