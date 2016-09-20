#include <iostream>
#include "DStructs.h"

using namespace std;
using namespace DStructs;

int main() {

  int num = 4;
  int num_2 = 6;
  int num_3 = 19;
  int test = 9;

  LinkedList<int> *linkedList = new LinkedList<int>();

  linkedList->put_front(num);
  linkedList->put_front(num_2);
  linkedList->put_front(num_3);
  linkedList->put_at(2, test);

  cout << linkedList->back() << endl;
  cout << linkedList->at(3) << endl;

  return 0;
}