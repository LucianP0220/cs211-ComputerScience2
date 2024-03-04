#include<iostream>
#include"LL.h"
using namespace std;

void LL::LLError(string errorMsg)
{
  cout<< errorMsg << endl;
}


LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

LL::~LL()
{
  while(!isEmpty())
    deleteFront();
}

LL::LL(const LL& source)
{
  this->front = this->rear = NULL;
  this->count = 0;
  node* p = source.front;
  while(p != NULL)
    {
      this->addFront(p->elem);
      p=p->next;
    }
}
void LL::addRear(el_t el)
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
void LL::addFront(el_t el)
{
  if(isEmpty())
    addRear(el);
  else
    {
      node* p = front;
      front = new node;
      front->elem = el;
      front->next = p;
      count++;
    }
}
el_t LL::deleteFront()
{
  if (isEmpty())
    LLError("The queue is empty. Cannot delete.");
  else
    {
      node* second = front->next;
      el_t p = front->elem;
      delete front;
      front = second;
      count--;
      if(count == 0)
        rear = NULL;
      return p;
    }

}
el_t LL::deleteRear()
{
  if(isEmpty())
    LLError("Error: list is empty.");
  else if(count == 1)
    {
      el_t temp = rear->elem;
      delete rear;
      front = rear = NULL;
      count--;
      return temp;
    }
  else
    {
      el_t temp = rear->elem;
      node* s;
      for(s=front; s->next!=rear; s=s->next)
	;
      delete rear;
      rear = s;
      count--;
      rear->next = NULL;
      return temp;

    }
}
bool LL::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;
  else
    return false;
}
void LL::displayAll()
{
  if(!isEmpty())
    {
      node* p = front;
      while(p != NULL)
        {
          //cout<< "[";
          cout<< p-> elem;
          p = p->next;
          //cout<< "]";
          cout<< " ";
        }
      cout<< endl;
    }
  else
    {
      LLError("[EMPTY]");
    }
}

void LL::deleteNode(el_t el)
{
  if(isEmpty())
    {
    return;
    }
  else
    {
      if(el == front-> elem)
	deleteFront();
      else
	{
	  node* pre;
	  node* del;
	  for(pre = front, del = front->next; del!= NULL && del->elem != el; pre = del, del = del->next)
	    ;
	  if (del!=NULL)
	    {
	      pre->next = del->next;
	      if(del == rear)
		rear = pre;
	      delete del;
	      count --;
	    }
	}
    }
}

void LL::deleteNodes(el_t el)
{
  if(isEmpty())
    return;
  else
    {
      if(el == front-> elem)
        deleteFront();
      if(count > 1)
	{
	  node* pre;
	  node* del;
	  for(pre = front, del = front->next; del!= NULL; pre = del, del = del->next)
	    {
	      if(del == rear && del-> elem == el)
		deleteRear();
	      else if(del->elem == el)
		{
		  pre->next = del->next;
		  delete del;
		  count--;
		}
	    }
		
	}
    }
}
		
	    
void LL::addInOrderAscend(el_t el)
{
  if(isEmpty())
    addFront(el);
  else if(el < front->elem)
    addFront(el);
  else
    {
      node* p = front;
      while(p->next!= NULL && p->next->elem < el)
	p = p-> next;
      node* n = new node;
      n->next = p->next;
      p->next = n;
      n->elem = el;
      count++;
	}
}

bool LL::search(el_t e)
{
  int count = 0;
  node* p = front;
  while(p != NULL)
    {
      count++;
      if(p->elem == e)
	{
	  cout<<count<<" nodes checked" << endl;
	  return true;
	}
      else
	p = p-> next;
    }
  cout<< count << " nodes checked" << endl;
      return false;    
}
