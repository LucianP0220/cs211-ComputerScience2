#ifndef DLL_H
#define DLL_H
#include<iostream>
#include <string>
using namespace std;

typedef int el_t;

struct node
{
  el_t elem;
  node* next;
  node* prev;
};

class DLL
{
 private:
  node* front;
  node* rear;
  int count;
  void DLLError(string errorMsg);
 
 public:
  DLL();
  ~DLL();
 DLL(const DLL& source);
  void addRear(el_t el);
  void addFront(el_t el);
  el_t deleteFront();
  el_t deleteRear();
  bool isEmpty();
  void displayAll();
  void deleteNode(el_t el);
  void deleteNodes(el_t el);
  void addInOrderAscend(el_t el);
  bool search(el_t el);
  void printAllReverseDLL();
  void printAllReverseDLL(node* p);
};
#endif
