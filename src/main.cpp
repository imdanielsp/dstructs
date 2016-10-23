#include <iostream>
#include "DStructs.h"


using namespace DStructs;

int main() {

  int num = 20;
  Node<int> *node = new Node<int>(num);
  Node<int> node2(4);


  std::cout << node->get_data() << std::endl;
  std::cout << node2.get_data() << std::endl;

  delete node;
  return 0;
}