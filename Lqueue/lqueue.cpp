#include<iostream>
#include"lqueue.h"
using namespace std;

/**************************
error message
 ************************/
void LQueue::queueError(string errorMsg)
{
  cout<< errorMsg << endl;
}


LQueue::LQueue()
{
  front = NULL;
  rear = NULL;
  count = 0;
}
/**************************
while queue is not empty 
delete all nodes
*automatic at end of program*
*****************************/
LQueue::~LQueue()
{
  while(!isEmpty())
    deleteFront();
}
/*********************
adds a new node at the rear
*************************/
void LQueue::addRear(el_t el)
{
  if(isEmpty())
    {
      front = new node;
      rear = front;
      front->elem = el;
      front->next = NULL;
      count++;
    }
  else
    {
      rear->next = new node;
      rear = rear->next;
      rear->elem = el;
      rear->next = NULL;
      count++;
    }
}
/******************************************
if queue is empty displays message
else removes front node
********************************************/
el_t LQueue::deleteFront()
{
  if (isEmpty())
    queueError("The queue is empty. Cannot delete.");
  else
    {
      node* second = front->next;
      int p = front->elem;
      delete front;
      front = second;
      count--;
      if(count == 0)
        front = rear = NULL;
      return p;
    }

}
/***************************
checking to see if queue is empty

***************************/
bool LQueue::isEmpty()
{
  if(front == NULL && rear == NULL && count == 0)
    return true;
  else
    return false;
}
/*****************************
if not empty displays all elements
else displays error messsage
****************************/
void LQueue::displayAll()
{
  if(!isEmpty())
    {
      node* p = front;
      while(p != NULL)
        {
          cout<< "[";
          cout<< p-> elem;
          p = p->next;
          cout<< "]"<< " ";
        }
      cout<< endl;
    }
  else
    {
      queueError("[EMPTY]");
    }
}

void LQueue::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
    {
      printAllReverse(p->next);
      cout << p-> elem;
    }
}
