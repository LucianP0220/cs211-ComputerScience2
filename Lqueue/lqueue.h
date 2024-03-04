#ifndef LQUEUE_H
#define LQUEUE_H
#include<iostream>
#include <string>
using namespace std;

typedef int el_t;

struct node
{
  el_t elem;
  node* next;
};

class LQueue
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string errorMsg);
  void printAllReverse(node*);

 public:
  LQueue();
  ~LQueue();
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void printAllReverse();  
};
#endif

