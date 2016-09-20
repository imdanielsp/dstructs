#include <iostream>
#include "DStructs.h"

using namespace std;
using namespace DStructs;

int main() {

  int num = 4;
  int num_2 = 6;
  int num_3 = 19;

  LinkedList<int> *linkedList = new LinkedList<int>();

  linkedList->push_back(num);
  linkedList->push_back(num_2);
  linkedList->push_back(num_3);

  for (int i = 0; i < linkedList->size(); i++)
    cout << (*linkedList)[i] << endl;

  return 0;
}