#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "checkInput.h"
#include "student.h"


const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

bool checkPassword(int choice);
int showMenu();
int showAdmMenu();
int showStuMenu();

void addStu(Student ar[], int& curId, int& count);
void showStuInfo(Student& s);
void allStuInfo(Student ar[], int count);
bool operator==(const Student& s, int id);
void addCourse (Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);

int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  int i;
  int choice;
  int c1;
  int c2;
  Student ar[SIZE];
 
do
  {
  choice = showMenu();
  if(choice == 1)
    {
     int a = checkPassword(choice);
      if(a == true)
	{
	  do
	    {
	      c1 = showAdmMenu();
	      switch(c1)
		{
		case 1: addStu(ar, curID, count);
		  break;
		  //case 2:addStuFromFile()
		  //case 3:removeStu();
		  //case 4:showStuInfo()
		  // case 5:allStuInfo()
		}
	    }while(c1 != 6);
	}
    }
  else if(choice == 2)
    {
    int b = checkPassword(choice);
      if(b == true)
	{
	  do
	    {
	      c2 = showStuMenu();
	      switch(c2)
		{
		case 1: addCourse(ar[i]);
		  break;
		case 2:dropCourse(ar[i]);
		  break;
		case 3:makePayment(ar[i]);
		  break;
		case 4:showStuInfo(ar[i]);
		  break;
		}
	    }while(c2 != 5);
	}
    }   
  }while(choice != 3);

 cout<< "\n----Ending Program----" <<endl;
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(ar,curID,count);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 again to a student ==> error --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "#######################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If you did, enter 20" << endl;
  cout << "#######################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If you did, enter 10.14" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
 
  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(ar, curID,count);
  addStu(ar, curID,count);
  addStu(ar, curID,count);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar,count);
  */
  return 0;
}



// ************************  PHASE 1  ****************************

void addStu(Student ar[], int& curID, int& count)
{
  int i; 
  string fN;
  string lN;
  char gen;
  //int curID = START
  cout<<"--Enter Students First Name--"<<endl;
  cin >> fN;
  cout<<"--Enter Students Last Name--"<<endl;
  cin >> lN;
  cout<<"--Enter Students Gender--"<<endl;
  cin >> gen;
  
  Student s(fN,lN,gen,curID);
  ar[i] = s;
  curID++;
  count++;
//case 1 of admission
//cin >>> fn, ln, gen

//create a student object. The first student created is given a stu id, 100000 (coming from const START).
//The second student gets 100001, the third student gets 100002, etc (notice curID in main).

//copy the info from the stu obj into the array at the appropriate slot

}                                                                                                                                      
void showStuInfo(Student& s )                                                                                       
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 


  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " <<  s.getFirst()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLast()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << s.getStuId() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << ", ";                                                                                                                 
 
                                                                                                                                              
  cout << "\nAmount owed: $" << s.getBalance()  << endl;
  //You have an operator overloading function to show a price object at once                    
  cout << endl;                                                                                                                               
 
  }


void allStuInfo(Student ar[], int count)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i = 0; i <= count; i++)
    showStuInfo(ar[0+i]);
}

 bool operator==(const Student& s, int id) 
{
  if(s.getStuId() == id)
    return true;
  else
    return false;
}

/*
 removeStu()
{
//Case 3 of Admission

//2 different messages

     //"student with id " << id << " doesn't exist" << endl;
     // f << " " << l << " has been removed." << endl;


}


 addStuFromFile()
{
//Case 2 of admission
}

*/





//*******************  PHASE 2 ****************************
 void addCourse(Student& s)
{
  int i;
  int crn;
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  cout << "Enter the CRN: ";
  cin >> crn;   
  i = s.addCourse(crn);
//3 different messages to show
  if(i == crn)
    {
      s.addFee(50, 14);
      cout<< crn << " has been added successfully" << endl;
    }
  else if(i == 0)
    {
      cout<< crn <<" was not added because you have " << crn << " already." <<  endl;
    }
  else 
    {
      cout<< "was not added because your schedule is full." <<  endl;
    }
  // " has been added successfully" << endl;
  // " was not added because you have " << crn << " already." <<  endl;
  // " was not added because your schedule is full." <<  endl;


}


 void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array.
  int crn;
  cout << "Enter the CRN: ";
  cin >> crn;

  if(s.dropCourse(crn))
    {
      s.reduceFee(50, 14);
      cout << crn << " has been dropped successfully" << endl;
    }
  else
    cout << crn <<" wasn't dropped from " << s.getFirst() << " because " << crn << " doesn't exist" << endl;

//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;


}


void makePayment(Student& s)
{
  int d;
  int c;
  Price p(d,c);
  //case 3 of student
  //FYI, I am passing one student to this function not the array.
  cout<< "You owe: $" << s.getBalance() << endl;
  cout<< "Enter your payment: $";
  cin>>d>>c; 
  s.reduceFee(d, c);  
}





//******************** PHASE 3 ****************************

bool checkPassword(int choice)
{
  int x;
  if(choice == 1)
    {
      cout<< "Enter your password: ";
      cin>> x;
      if(x == PASSWORD)
	{
	  return true;
	}
      else
	{
	  cout<< "The password is wrong.";
	  return false;
	}
    }
  else if(choice == 2)
    {
      int id;
      int x;
      cout<< "Enter the student id: ";
      cin>> id;
      int pw = id % (PRIME1 * PRIME2);
      cout<< "Enter the password: ";
      cin>> x;
      if(x == pw)
	{
	  return true;
	}
      else
	{
	  cout<<"The password is wrong."<< endl;;
	  return false;
	}
    }
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}

/*
 findStu()
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


 viewStuInfo()
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}

*/

int showMenu()
{
  int choice;
  cout << "\n========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



