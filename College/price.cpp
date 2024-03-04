#include"price.h"
using namespace std;

Price::Price()
{
  dollars = 0;
  cents = 0;
}

Price::Price(int dollars, int cents)
{
  this->dollars = dollars;
  this->cents = cents;
}

Price Price::operator+(const Price& sec)
{
  int nDollar = this->dollars + sec.dollars;
  int nCents = this->cents + sec.cents;
  if(nCents >= 100)
    {
    
      nCents = nCents - 100;
      nDollar = nDollar +1;
    }

  Price nPrice(nDollar, nCents);
  return nPrice;
}

Price Price::operator-(const Price& other)
{
  int p1 = this->dollars * 100 + this->cents;
  int p2 = other.dollars * 100 + other.cents;
  int diff;
  int d;
  int c;

  if(p1 >= p2)
    {
      diff = p1 - p2;
      d = diff/100;
      c = diff%100;
    }

  Price diffo(d, c);
  return diffo;
}

  ostream& operator<<(ostream& o, const Price& p)
  {
    if(p.cents == 0)
      o<<p.dollars<<".00";
    else if(p.cents < 10)
      o<<p.dollars<<".0"<<p.cents;
    else
      o<<p.dollars << "." <<p.cents;

    return o;
  }
