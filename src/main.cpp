#include <iostream>
#include <cstdlib>
#include <chrono>
#include <functional>
#include <string>
#include <vector>
#include "DStructs.h"

#define DSTRUCT_DEBUG true

using namespace DStructs;

int left(int i) {
  return 2*i + 1;
}

int right(int i) {
  return 2*i + 2;
}

bool comp(int l, int r) {
  return l > r;
}

void heapify(std::vector<int>& arr, int i, bool (*comp)(int l, int r)) {
  auto l = left(i);
  auto r = right(i);
  int largest;

  if (l < arr.size() && comp(arr[l], arr[i])) {
    largest = l;
  } else {
    largest = i;
  }

  if (r < arr.size() && comp(arr[r], arr[i])) {
    largest = r;
  }

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, largest, comp);
  }
}

void buildHeap(std::vector<int>& arr) {
  auto half = std::floor(arr.size()/2);
  for (int i = half; i >= 0; i--) {
    heapify(arr, i, comp);
  }
}


int main() {
  auto list = new DStructs::LinkedList<int>(10, 5);
  
  return 0;
}
