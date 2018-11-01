#include <iostream>
#include <cstdlib>
#include <chrono>
#include <functional>
#include <string>
#include <vector>
#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

int main() {
  MaxHeap<int> v;
  v.insert(9);
  v.insert(2);
  v.insert(4);
  v.insert(10);
  v.insert(1);
  v.insert(1);
  v.insert(2);
  v.insert(31);

  v.forEach([](const auto item) {
    std::cout << item << std::endl;
  });

  return 0;
}
