/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Lucian Pate
*****************************************************/

#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T ar[], int n)
{
  for(int i = 0; i < n; i++)
    {
      cout<< "Enter a number: ";
      cin>> ar[i];
    }
}
/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T>
void print(const T ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout<< ar[i]<< " ";
}
/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template<class T>
int getHighest(const T ar[], int n)
{
  int highIndex = 0;
  for(int i = 1; i < n; i++)
    if(ar[i] > highIndex)
      highIndex = i;

  return highIndex;
}
/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template<class T>
int getLowest(const T ar[], int n)
{
  int lowIndex = 0;
  for(int i = 1; i < n; i++)
    if(ar[i] < lowIndex)
      lowIndex = i;

  return lowIndex;
}
/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template<class T>
double getAvg(const T ar[], int n)
{
  double total = 0;
  double avg;
  for(int i = 0; i < n; i++)
    total+=ar[i];
  avg = total/n;

  return avg;
}
/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template<class T>
int unique(const T ar[], int n)
{
  int count = 0;
//uniqAr in the caller will be filled with only unique numbers
  for(int i = 0; i < n; i++)
    {
      int k;
      for (k = 0; k < i; k++)
	if(ar[i] == ar [k])
	  break;
      if (i == k)
      count++;
    } 
  return count;
}

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

/**************************************
bubble sort

array is an array of any data type
size is the size of the array
******************************************/
template<class T>
void bubbleSort(T array[], int N)
{
  bool sorted = false;
  int i = 1;
  while(!sorted)//while array is not sorted
    {
      sorted = true;
      for(int j = 0; j < N - i; j++)
	{
	  if(array[j]>array[j+1])
	    {
	      T temp = array[j];
	      array[j] = array[j+1];
	      array[j+1] = temp;
	      sorted = false;
	    }
	}
      i++;
    }
}

/*****************************************************
This function finds the key in an array

array is an array of any type
size is the size of the array
key is the item to be found in array

****************************************************/
template<class T1, class T2>
  int find(const T1 array[], int size, const T2& key)
{

  for(int i = 0; i < size; i++)
    {
      if (array[i] == key)
        return i;
    }
  return -1;
}

/******************************************
This function removes an item of an array

array is an array of any type
size if the size of the array
key is the item to be removed

*****************************************/
template<class T>
bool remove(T array[], int size, int key)
{
  int i;
  i = find(array, size, key);   
  if(i != -1)
    {
      for(int n = i; n < size-1; n++)
	array[n] = array[n+1];
      return true;
    }


  return false;
}
#endif
