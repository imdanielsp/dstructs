#include <iostream>
#include <cstdlib>
#include <chrono>

#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

inline void insert_data_to_bst(int range) {
  BST<int> bst;

  int val;

  for (int i = 0; i < range; i++) {
    val = rand() % range;
    bst.insert_data(val);
  }
}
int main() {

  srand((unsigned int) time(0));

  int range = 10000000;
  int rounds = 50;
  long long int time_average = 0;

  for (int i = 0; i < rounds; i++) {
    auto start_time = std::chrono::high_resolution_clock::now();

    insert_data_to_bst(range);

    auto stop_time = std::chrono::high_resolution_clock::now();

    time_average += std::chrono::duration_cast<std::chrono::milliseconds>
        (stop_time - start_time).count();
    std::cout << "Round #" << i << " done." << std::endl;
  }


  std::cout << std::endl
            << "After "
            <<  rounds
            << " round(s) inserting "
            << range
            << " random int to the BST, in average, it took: "
            << time_average/rounds
            << " milliseconds."
            << std::endl;

  return 0;
}
