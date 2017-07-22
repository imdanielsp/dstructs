/* *
 * MIT License
 *
 * Copyright (c) 2017 Daniel Santos
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
 * */
#ifndef DSTRUCTS_INSERTION_SORT_H
#define DSTRUCTS_INSERTION_SORT_H

#include <iterator>
#include <functional>
#include <iostream>

/**
 * \brief   Insertion sort implementation. Average time complexity O(n^2).
 * Size complexity O(n).
 *
 * \param   T& container - The container must implement random access by index.
 * */
template <class T>
void insertion_sort(T& container) {
  for (int j = 1; j < container.size(); j++) {
    int temp = container[j];
    int i = j - 1;
    while (i >= 0 && container[i] > temp) {
      container[i + 1] = container[i];
      i--;
    }
    container[i + 1] = temp;
  }
}

/**
 * \brief   Insertion sort implementation. Average time complexity O(n^2).
 * Size complexity O(n). This template function take a function as an argument
 * that is used in the algorithm to compare the elements in the container.
 *
 * \param   T& container - The container must implement random access by index.
 *          C comparable - A function that takes to parameter and returns bool.
 * */
template <class T, class C>
void insertion_sort(T& container, C comparable) {
  for (int j = 1; j < container.size(); j++) {
    int temp = container[j];
    int i = j - 1;
    while (i >= 0 && comparable(container[i], temp)) {
      container[i + 1] = container[i];
      i--;
    }
    container[i + 1] = temp;
  }
};

#endif //DSTRUCTS_INSERTION_SORT_H
