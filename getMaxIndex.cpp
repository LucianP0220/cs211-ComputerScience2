#include<iostream>
using namespace std;
int getMaxIndex(int ar[], int SIZE);

int main()
{






int getMaxIndex( int ar[], int SIZE)
{
  int max = 0;
  for(int i = 1; i < SIZE; i++)
    {
      if (ar[i] > ar[max])
        max = i;
    }
  return max;
}
