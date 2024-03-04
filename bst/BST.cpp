#include <iostream>
#include <cstdlib> //for rand()
#include "LL.h"
using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e, right = NULL; left = NULL;} //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;
  void insertNode(Node*&, el_t);
  void inOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  bool searchRec(el_t e, Node* p);
  int getMaxLength(Node* p);

public:
  BST();
  ~BST();
  void destroy(Node* p);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  void insertNode(el_t);
  bool search(el_t e);
  bool searchRec(el_t e);
  int getMaxLength();
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  destroy(root);
}

void BST::destroy(Node* p)
{
  if(p == NULL)
    return;
  destroy(p-> left);
  destroy(p-> right);
  cout << p-> elem << "-->";
  delete p;
}

void BST::inOrderPrint()
{
  inOrderPrint(root);
}
void BST::inOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p->left);
  cout << p->elem << "-->";
  inOrderPrint(p->right);
}

void BST::preOrderPrint()
{
  preOrderPrint(root);
}
void BST::preOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  cout << p->elem << "-->";
  preOrderPrint(p->left);
  preOrderPrint(p->right);
}

void BST::postOrderPrint()
{
  postOrderPrint(root);
}
void BST::postOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  postOrderPrint(p->left);
  postOrderPrint(p->right);
  cout << p->elem << "-->";
}



void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  //You want to know how many times it loops to find e.
  //declare a counter. 

  Node* p = root;
  int count = 0;
  while(p !=NULL)
    {
      count++;
      if(e == p-> elem)
	{
	  cout<< count << " nodes checked" << endl;
	  return true;
	}
      else if(e < p-> elem)
	p = p-> left;
      else
	p = p-> right;
    }
  //display the counter
  cout<< count << " nodes checked" << endl;
  return false;
}

bool BST::searchRec(el_t e)
{
  return searchRec(e,root);
}
bool BST::searchRec(el_t e, Node* p)
{
  if(p == NULL)
    return false;
  else if(e == p-> elem)
    return true;
  else if(e < p->elem)
    return searchRec(e, p->left);
  else
    return searchRec(e, p-> right);
}

int BST::getMaxLength()
{
  return getMaxLength(root);
}

int BST::getMaxLength(Node* p) 
{
  if(p == NULL) 
    return 0;
  else if(getMaxLength(p->left) >  getMaxLength(p->right))
    return getMaxLength(p->left)+ 1;
  else
    return getMaxLength(p->right) + 1;
}

int main()
{


  BST b;
  BST b2;
  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(6);
  b.insertNode(1);
  b.insertNode(0);
  b.insertNode(4);
  b.insertNode(7);
  b.insertNode(20);
  cout << "---- in order -----" << endl;
  b.inOrderPrint();
  cout << "\n---- pre order -----" << endl;
  b.preOrderPrint();
  cout << "\n---- post order -----" << endl;
  b.postOrderPrint();
  cout<<"\n---- max length -----" << endl;
  cout<< b.getMaxLength();

  b2.insertNode(5);
  b2.insertNode(3);
  b2.insertNode(8);
  b2.insertNode(6);
  cout<<"\n"<< b2.getMaxLength();
  cout<<"\n---- search rec -----" << endl;
  cout<<b.searchRec(9);
  cout << "\n--- destructor gets called ---" << endl;



  /*
  srand(time(0)); //you need to include cstdlib

  BST b;
  LL l1;
  int n;
  int key;

  for(int i = 1; i <= 10000; i++)
    {
      n = rand()%10000 + 1;
      b.insertNode(n);
      l1.addRear(n);
    }


  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;
 
  if(b.search(key))
    cout<< "Found"<<endl;
  else
    cout<<"Not Found" << endl;

  cout << "LL************************" << endl;
  
  if(l1.search(key))
    cout<< "Found"<<endl;
  else
    cout<<"Not Found" << endl;
  */
  return 0;
}
