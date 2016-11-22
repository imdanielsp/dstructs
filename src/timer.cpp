/**
 * MIT License
 *
 * Copyright (c) 2016 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * \brief       This program is basically used to time any data structure or
 * algorithms. It is meant to be use for any cases, otherwise please let us
 * know.
 * */
#include <iostream>

#include "DStructs.h"

/**
 * \brief       This is the runner function. This function should be
 * filled with the code that you want to time/test.
 * */
inline void runner() {
  // Your code goes here
  // Example

  DStructs::BST<int> bst;
  unsigned int range  = 10000000;

  for (int i = 0; i < range; i++)
    bst.insert_data(rand() % range);

  return;
}

/**
 * \brief       This functions returns the number of T the runner
 * function took to complete. Where T can be one of the following list:
 * - std::chrono::seconds
 * - std::chrono::milliseconds
 * - std::chrono::microseconds
 * - std::chrono::nanoseconds
 *
 * \return      auto
 * */
template <typename T>
long long int timer(void (*foo)());

int main(int argc, char* argv[]) {
  // Random seed in case of usage of rand()
  srand((unsigned int) time(0));

  long long int duration = timer<std::chrono::milliseconds>(&runner);

  std::cout << "The time it took "
            << duration
            << " T to run the runner function. Where T is the passed type "
                "above."
            << std::endl;

  return 0;
}

template <typename T>
long long int timer(void (*func)()) {
  const std::type_info& type = typeid(T);

  if (type.hash_code() == typeid(std::chrono::hours).hash_code() ||
      type.hash_code() == typeid(std::chrono::minutes).hash_code()) {

    std::cerr << "Invalid type for the timer." << std::endl;
    exit(1);
  }

  auto start_time = std::chrono::high_resolution_clock::now();

  // Run the function
  (func)();

  auto stop_time = std::chrono::high_resolution_clock::now();

  return std::chrono::duration_cast<T>(stop_time - start_time).count();

}
