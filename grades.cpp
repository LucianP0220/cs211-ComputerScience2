/*********************
lucian pate
cs211
lab
********************/
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void calcLowHighAverage(int t1, int t2, int t3,int& low, int& high, double& avg);

int main()
{
  int id;
  int t1;
  int t2;
  int t3;
  int low;
  int high;
  double avg;
  string fname;
  string lname;

  ifstream fin;
  ofstream fout;

  fin.open("stuscores.dat");
  if(!fin)
    {
      cout<< "Cannot open input file" << endl;
    }
  else
    {
      fout.open("grades.out");
      fout<< setw(10) << left << "ID";
      fout<< setw(10) << right << "Lowest";
      fout<< setw(10) << "Highest";
      fout<< setw(10) << "Average" <<endl;

      fin>> id;
      fin>> fname;
      fin>> lname;
      fin>> t1;
      fin>> t2;
      fin>> t3;
      while(fin)
        {
          calcLowHighAverage(t1,t2,t3,low,high,avg);

          fout<<fixed<<setprecision(2);
          fout<< setw(10)<< left << id;
          fout<< setw(10)<< right << low;
          fout<< setw(10)<< high;
          fout<< setw(10)<< avg;
          fout<<endl;

          fin>> id;
          fin>> fname;
          fin>> lname;
          fin>> t1;
          fin>> t2;
          fin>> t3;

        }
    }
  return 0;

}
void calcLowHighAverage(int t1, int t2, int t3,int& low, int& high, double& avg)
{
  double sum;
  if (t1 < t2 && t1 < t3)
    low = t1;
  else if(t2 < t1 && t2 < t3)
    low = t2;
  else
    low = t3;

  if (t1 > t2 && t1 > t3)
    high = t1;
  else if(t2 > t1 && t2 > t3)
    high = t2;
  else
    high = t3;

  sum = t1+t2+t3;
  avg = sum / 3;
}
