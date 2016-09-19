#include <iostream>
#include "DStructs.h"

using namespace std;
using namespace DStructs;

int main() {

  int num = 4;
  int num_2 = 6;
  int num_3 = 19;

  LinkedList<int> *linkedList = new LinkedList<int>();

  linkedList->put_front(num);
  linkedList->put_front(num_2);
  linkedList->put_front(num_3);

  for (int i = 0; i < linkedList->size(); i++) {
    std::cout << (*linkedList)[i] << std::endl;
  }

  linkedList->clear();

  for (int i = 0; i < linkedList->size(); i++) {
    std::cout << (*linkedList)[i] << std::endl;
  }

  return 0;
}