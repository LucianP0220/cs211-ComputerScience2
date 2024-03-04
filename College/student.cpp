#include"student.h"
using namespace std;

Price balance;

Student::Student()
{
  first = "unknown";
  last = "unknown";
  gender = 'x';
  stuId = -1;
}
Student::Student(string f, string l, char g, int id)
{
  first = f;
  last = l;
  gender = g;
  stuId = id;
  numClasses = 0;
  classes[MAX];
  // Price balance;
}

string Student::getFirst() const
{
  return first;
}

string Student::getLast() const
{
  return last;
}

char Student::getGender() const
{
  return gender;
}

int Student::getNumClasses() const
{
  return numClasses;
}

int Student::getStuId() const
{
  return stuId;
}

int Student::getClassOf(int i) const
{
  return classes[i];
}

Price Student::getBalance() 
{
  return balance;
}

int Student::addCourse(int crn)
{
  int i;
  i  = find(classes, MAX, crn);
  if(numClasses < MAX)
    {
      if (i == -1)
        {
          classes[numClasses++] = crn;
          return crn;
        }

      else if(i == 1)
	{
	  return 0;
	}
    }
  else
    return -1;
}

void Student::viewAllCourses()
{
  if(numClasses > 0)
    return print(classes, numClasses );

  else
    cout<< "none"<<endl;
}

bool Student::dropCourse(int crn)
{
  bool i;
  i = remove(classes, MAX, crn);
  if(i == true)
    {
      numClasses--;
      return true;
    }
  else
    return false;

}

void Student::addFee(int d, int c)
{
  Price p(d,c);
  balance = balance + p;

}
void Student::reduceFee(int d, int c)
{
  Price p(d,c);
  balance = balance - p;
}
