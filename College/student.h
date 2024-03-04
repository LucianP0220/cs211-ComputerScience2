#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include"array.h"
#include"price.h"
using namespace std;

const int MAX = 6;

class Student
{
 private:
  string first;
  string last;
  char gender;
  int numClasses;
  int stuId;
  int classes[MAX];

 public:
  Student();
  Student(string f, string l, char g, int id);
  string getFirst() const;
  string getLast() const;
  char getGender() const;
  int getNumClasses() const ;
  int getStuId() const;
  int getClassOf(int i) const;
  Price getBalance();
  int addCourse(int crn);
  void viewAllCourses();
  bool dropCourse(int crn);
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};
#endif
