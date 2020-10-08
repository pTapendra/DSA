
/*2. WAP to create a structure DATE with its member: day, month and year.
Write a function which takes two pointer variables of type DATE to calculate the age of person (i.e. pass structure by reference).
*/
#include<iostream>
using namespace std;
struct DATE{
    int day;
    int month;
    int year;
 DATE() {}
 DATE(int d, int m, int y)
  {
    day = d;
    month = m;
    year = y;
  }
  
};
DATE* CalculateAge(DATE* present, DATE* dob)
{
      int month[] = { 31, 28, 31, 30, 31, 30, 31,  
                          31, 30, 31, 30, 31 }; 
     DATE *temp = new DATE(0, 0, 0);
 if (dob->day > present->day)
    {
      present->day = present->day + month[dob->month - 1];
      present->month = present->month -1;
    }

  if(dob->month > present->month)
    {
      present->year = present->year - 1;
      present->month = present->month + 12;
    }
    temp->day = present->day - dob->day;
  temp->month = present->month - dob->month;
  temp->year = present->year - dob->year;

  return temp;
  }
int main()
{
  DATE *person=new DATE;
  DATE *now = new DATE(1, 9, 2020);
  
  cout<<"Enter date of birth"<<endl;
  cin>>person->day>>person->month>>person->year;
  DATE *age = CalculateAge(now, person);
  cout << age->year << " years  " << age->month << " months  " << age->day << " days old";
  }

