
#include<iostream>
using namespace std;

void showProgInfo();
void getInfo(string &name, char &gender, int &age);
bool verifyEligibility(char gender, int age);
void printLetter(bool n,string name);


int main()
{
  string name;
  char gender;
  int age;
  bool n;

  showProgInfo();
  getInfo(name,gender,age);
  n = verifyEligibility(gender, age);
  printLetter(n,name);



  return 0;
}

void showProgInfo()
{
  cout<<"*****************************************************************"<<endl;
  cout<<"This program will tell you if you are eligible to join the military."<<endl;
  cout<<"*****************************************************************" <<endl;
}

void getInfo(string &name, char &gender, int &age)
{

  cout<<"Enter first name: ";
  cin>> name;
  cout<<"Enter gender: ";
  cin>> gender;
  cout<< "Enter age: ";
  cin>> age;
}

bool verifyEligibility(char gender, int age)
{

  if(gender == 'F' || gender == 'f')
    return false;
  else if (age < 18)
    return false;
  else
    return true;
}

void printLetter(bool n,string name)
{
  if(n)
    {
      cout<< "Dear " << name << " please consider joining the military.\n"<< endl;
    }
  else
    {
      cout<< "Thank you for applying.\n"<<endl;
    }
}
