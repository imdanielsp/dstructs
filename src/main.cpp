#include <iostream>
#include "DStructs.h"

#define DEBUG

using namespace DStructs;

int main() {

  LinkedList<int> *linkedList = new LinkedList<int>();

  linkedList->push_back(4);
  linkedList->push_back(5);
  linkedList->push_back(6);

  delete linkedList;
//  std::cout << linkedList->front() << std::endl;
  return 0;
}