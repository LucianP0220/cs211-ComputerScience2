#include <iostream>
#include"lqueue.h"
using namespace std;

int main()
{
  LQueue lq;
  LQueue lq2;

  if (lq.isEmpty())
    cout << "The queue is empty" << endl;
  else
    cout << "The queue is not empty" << endl;

  lq.displayAll();

  lq.addRear(1);
  lq.addRear(2);
  lq2 = lq;
  lq.deleteFront();
  lq2.displayAll();

  lq.addRear(2);
  lq.addRear(3);
  lq.addRear(4);

  lq.displayAll();

  cout << lq.deleteFront() << endl;
  cout << lq.deleteFront() << endl;
  cout << lq.deleteFront() << endl;

  lq.displayAll();

  if (lq.isEmpty())
    cout << "The queue is empty" << endl;
  else
    cout << "The queue is not empty" << endl;

  cout << lq.deleteFront() << endl;

  if (lq.isEmpty())
    cout << "The queue is empty" << endl;
  else
    cout << "The queue is not empty" << endl;

  lq.displayAll();

  return 0;
}
