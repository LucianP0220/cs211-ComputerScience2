#include<iostream>
#include<cstdlib>
#include"queue.h"
using namespace std;
/***********************
initialies the queue
***********************/
Queue::Queue()
{
  front = 0;
  rear = -1;
  count = 0;
}
/*************************
return if queue is empty or not
****************************/
bool Queue::isEmpty() const
{
  if(count == 0)
    return true;
  else
    return false;
}
/*************************
returns if queue is full or not
****************************/
bool Queue::isFull() const
{
  if(count == QUEUE_SIZE)
    return true;
  else
    return false;
}
/************************
adding element to queue
or else if full display error
*************************/
void Queue::add(el_t e)
{
  if(isFull())
    queueError("Queue Overflow");
  else
    {
      rear = (rear+1) % QUEUE_SIZE;
      el[rear] = e;
      count++;
    }
}
/***********************
removing element from queue
or if empty display error
************************/
el_t Queue::remove()
{
  if(isEmpty())
    queueError("Queue Underflow");
  else
    {
      el_t e = el[front];
      front = (front + 1) % QUEUE_SIZE;
      count--;
      return e;
    }

}
/*******************
returning the front element 
of the queue
***********************/
el_t Queue::getFront()
{
  if(!isEmpty())
    return el[front];
  else
    queueError("Queue is Empty");
}

void Queue::goToBack()
{
  add(remove());
}
/***********************
returning the size of the 
queue
**********************/
int Queue::getSize() const
{
  return count;
}

ostream& operator<<(ostream& o, const expr& e)
{

  o<< e.oprd1 << e.oprt << e.oprd2;
  return o;
}

/*************************
displaying all elements of 
the queue
****************************/
void Queue::displayAll()
{
  if (!isEmpty())
    {
      int temp = front;
      int f;

      cout << endl;
      for (int i = 0; i < count; i++)
        {
          f = temp % QUEUE_SIZE;
          cout << el[f] << " ";
          temp++;
        }
      cout << endl;
    }
  else
    {
      queueError("Queue is empty");
    }
}

/************************
private error message
************************/
void Queue::queueError(string errorMsg)
{
  cout<< errorMsg << endl;
  // exit(1);
}
