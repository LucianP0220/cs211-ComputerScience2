#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string.h>
using namespace std;

/******************************
Place the following code in queue.h
********************************/
//create an enumurate type
enum op {ADD, SUB, MULT, DIVI};
//create a struct that will have an operand, a operator, another operand
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};
const int QUEUE_SIZE = 10;
typedef expr el_t;

class Queue
{
 private:
  el_t el[QUEUE_SIZE];
  int count;
  int front;
  int rear;
  void queueError(string errorMsg);

 public:
  Queue();
  bool isEmpty() const;
  bool isFull() const;
  void add(el_t e);
  el_t remove();
  el_t getFront();
  void goToBack();
  int getSize() const;
  friend  ostream& operator<<(ostream& o, const expr& q);
  void displayAll();
};
#endif


