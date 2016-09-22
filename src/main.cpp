#include <iostream>
#include "DStructs.h"

#include <queue>
using namespace std;
using namespace DStructs;

int main() {

  Queue<int> q;
  q.push(5);
  q.push(2);
  q.push(9);

  queue<int> stdQ;

  cout << q.front() << endl;

  return 0;
}