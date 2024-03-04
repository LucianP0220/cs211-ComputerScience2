#include<iostream>
#include<string.h>
#ifndef PRICE_H
#define PRICE_H
using namespace std;

class Price
{
  
 private:
  int dollars;
  int cents;

 public:
  Price();
  Price(int dollars, int cents);
  Price operator+(const Price& sec);
  Price operator-(const Price& other);
  friend  ostream& operator<<(ostream& o, const Price& p);

};
#endif


