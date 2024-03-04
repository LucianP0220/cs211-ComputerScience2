/*********************************************************
Template provided by Kazumi Slott

Name: Lucian Pate
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
#include"queue.h"
#include"checkInput.h"
using namespace std;

void showMenu();

int main()
{
  Queue q;
  int choice;
  char ch;
  do
    {
      showMenu();
      choice = getData(1, 7, "Invalid Choice");

      switch(choice)
        {
        case 1 : cout<<"\nAdd: ";
	  cin>>ch;
          q.add(ch);
          break;
        case 2 : q.remove();
          break;
        case 3 : q.getFront();
          break;
        case 4 : q.goToBack();
          break;
        case 5 : cout<<"\ngetSize: " << q.getSize()<<endl;;
          break;
        case 6 : q.displayAll();
	    cout<<endl;
          break;
	}
  }while(choice != 7);
  
  return 0;
}


void showMenu()
{
  cout << "1: add a new element" << endl; //(testing add(), isFull())
  cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
  cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
  cout << "4: go back to the rear" << endl; //(testing goToBack())
  cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
  cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
  cout << "7: quit program" << endl;
}
