#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<iostream>
using namespace std;
template <class T>
class myVector
{
private:
  T* ar; //pointer to an array
  int num; //the number of elements in the array pointed to by ar
public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T operator[](int index) const;
  void erase(int index);
  void insert(int index, const T& e); //the new element, e, will sit at index
};
template <class T> //above each function of this class, you need this.
myVector<T>::myVector() //use T even if you are not using T in this function.
{
  //initialize ar and num
  ar = NULL;
  num = 0;

  }
template <class T>
myVector<T>::~myVector() //destructor – we will talk more about it in the upcoming lectures
{//The destructor is called automatically when an object of the class goes out of scope
  //The destructor cannot be called by the programmer.
  //Don’t forget to delete the array in heap!
  if(ar != NULL)
    delete [] ar; //if ar points to an array, delete it
}
template <class T>
void myVector<T>::push_back(const T& e)//e could be big. Use pass by reference with const
{
  T* v = new T[num+1];
  for(int i = 0; i < num; i++)
    {
      *(v+i)= *(ar+i);
    }
  *(v+num) = e;
  num+=1;
  delete[]ar;
  ar = v;
  //adds a new element at the end
}
template <class T>
int myVector<T>::size() const
{
  return num;
}

template <class T>
T myVector<T>::operator[](int index) const
{
  return ar[index];
}

void print(myVector<int>&v);
/*
int main()
{
  myVector<int> v; //You can use any data type
  //test your myVector functions.
  // Call push_back() multiple times
  v.push_back(1);
  v.push_back(2);
  v.push_back(9);
  v.push_back(3);
  //Call print() to show all the elements in the vector
  print(v);
  v.erase(2);
  print(v);
  v.erase(3);
  v.insert(1, 9);
  print(v);
  v.insert(4, 5);
  print(v);
  v.insert(6, 7);
  return 0;
}
*/

void  print(myVector<int>&v)
{
  for(int i = 0; i < v.size() ; i++)
    cout<< v[i]<<" ";
  cout<<endl;
  //display each element
}

template <class T> 
void myVector<T>::erase(int index)
{
  if(index < num)
    {
      for (int i = index; i < num-1; ++i) 
	{
	  ar[i] = ar[i+1];
	}
      num--; 
    }
  else
    cout<<"illegal index"<<endl;
}

template <class T>
void myVector<T>::insert(int index, const T& e)
{
  if(index < num+1 && index >= 0)
    {
      for(int i = num; i > index; i--)
	{
	  ar[i] = ar[i-1];
	}
      ar[index] = e;
      num++;
    }
  else
    cout<<"illegal index"<<endl;
}
#endif 

