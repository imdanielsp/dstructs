#include <iostream>


#include "Linked_List/node.h"

int main() {

  DStructs::Node<int> *node = new DStructs::Node<int>();

  node->set_data(5);

  std::cout << node->get_data() << std::endl;


  return 0;
}