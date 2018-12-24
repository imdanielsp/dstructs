#include <iostream>
#include <thread>
#include <chrono>

#include "DStructs.h"

int main() {
  auto list = new DStructs::LinkedList<int>();

  std::thread t1([](auto l) {
    for (int i = 0; i < 5; i++) {
      l->push_back(i);
    }
  }, list);

  std::thread t2([](auto l) {
    for (int i = 5; i < 10; i++) {
      l->push_back(i);
    }
  }, list);

  std::thread r([](auto l) {
    for (int i = 0; i < 15; i++) {
      l->forEach([](auto it) { std::cout << it << " "; });
      std::cout << std::endl;
    }
  }, list);

  t1.join();
  t2.join();
  r.join();

  std::cout << list->size() << std::endl;

  list->forEach([](auto it) { std::cout << it << " "; });

  return 0;
}
