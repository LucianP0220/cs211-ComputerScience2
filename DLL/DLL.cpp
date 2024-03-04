#include<iostream>
#include"DLL.h"
using namespace std;

void DLL::DLLError(string errorMsg)
{
  cout<< errorMsg << endl;
}


DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

DLL::~DLL()
{
  while(!isEmpty())
    deleteFront();
}

DLL::DLL(const DLL& source)
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
void DLL::addRear(el_t el)
{
  if(isEmpty())
    {
      front = rear = new node;
      front->next = NULL;
      front->prev = NULL;
    }
  else
    {
      rear->next = new node;
      rear -> next -> prev = rear;;
      rear = rear -> next;
    }
  rear -> next = NULL;
  rear -> elem = el;
  count++;
    
}
void DLL::addFront(el_t el)
{
  if(isEmpty())
    addRear(el);
  else
    {
      node* p = front;
      front = new node;
      front->elem = el;
      front->next = p;
      p-> prev = front;
      front -> prev = NULL;
      count++;
    }
}
el_t DLL::deleteFront()
{
  el_t p;
  if (isEmpty())
    DLLError("The queue is empty. Cannot delete.");
  else if(count == 1)
    {
      p = front->elem;
      delete front;
      front = rear = NULL;
    }
  else
    {
      p = front -> elem;
      front = front -> next;
      delete front -> prev;
      front -> prev = NULL;
    }
  count--;
  return p;
}

el_t DLL::deleteRear()
{
  if(isEmpty())
    DLLError("Error: list is empty.");
  else if(count == 1)
    {
      return deleteFront();
    }
  else
    {
      el_t temp = rear->elem;
      rear = rear-> prev;
      delete rear-> next;
      rear-> next = NULL;
      count--;
      return temp;

    }
}

bool DLL::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;
  else
    return false;
}

void DLL::displayAll()
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
      DLLError("[EMPTY]");
    }
}

void DLL::deleteNode(el_t el)
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
	  node* del;
	  for(del = front->next; del!= NULL && del->elem != el; del = del->next)
	    ;
	  if (del == NULL)
	    return;
	  else if(del == rear)
	    {
	      rear = del->prev;
	      rear-> next = NULL;
	    }
	  else  if(del != NULL)
	    {
		del-> prev-> next = del-> next;
		del-> next-> prev = del-> prev;
	    }
	
	  delete del;
	  count --;
	}
    }
}


void DLL::deleteNodes(el_t el)
{
  if(isEmpty())
    return;
  else
    {
      if(el == front-> elem)
        deleteFront();
      if(count > 1)
	{
	 
	  node* del;
	  for(del = front; del!= NULL; del = del->next)
	    {
	      if(del == front && del-> elem == el)
		deleteFront();
	      else  if(del == rear && del-> elem == el)
                deleteRear();
	      else if(del->elem == el)
		{
		  del-> prev-> next = del->next;
		  del-> next-> prev = del->prev;
		  delete del;
		  count--;
		}
	    }
		
	}
    }
}
			    
void DLL::addInOrderAscend(el_t el)
{
  if(isEmpty())
    addFront(el);
  else if(el < front->elem)
    addFront(el);
  else if(el > rear->elem)
    addRear(el);
  else
    {
      node* p = front;
      while(p->next!= NULL && p->next->elem < el)
	p = p-> next;
      node* n = new node;
      n->next = p->next;
      n->prev = p;
      p->next->prev = n;
      p->next = n;
      n->elem = el;
      count++;
    }
}

bool DLL::search(el_t e)
{
  if(isEmpty())
    return false;
  else
    {
      node* p;
      for(p = front; p != NULL; p = p->next)
	{
	  if(p->elem == e)
	    return true;
	}
      return false;
    }
}

void DLL::printAllReverseDLL()
{
  printAllReverseDLL(rear);
}
void DLL::printAllReverseDLL(node* p)
{
  for(p; p!=NULL; p=p->prev)
    {
      cout<<p->elem<< " ";
    }
  
}
