#include <iostream>
#include "DStructs.h"

#define DEBUG

using namespace DStructs;

int main() {

  Deque<int> deque;
  int foo;
  deque.push(5);
  deque.push(6);
  deque.push(7);

  for (int i = 0; i < 5; i++) {
    std::cout << "About to push to front" << std::endl;
    deque.push_front(i);
    std::cout << "Done pushing front" << std::endl;
    std::cout << "Enter a number to proceed" << std::endl;
    std::cin >> foo;
  }
  std::cout << std::endl;
  return 0;
}