#ifndef STUDENT_H
#define STUDENT_H

#include<fstream>
#include<iostream>

using namespace std;
class student
{
  char name[20];
  int rollno;
  int marks[5];
public:
  student()
  {
    marks[0] = marks[1] = marks[2] = marks[3] = marks[4] = -1;
  }

  int getroll()
  {
    return rollno;
  }

  void input()
  {
    cout<<"\nEnter the name: ";
    cin>>name;
    cout<<"\nEnter the roll number: ";
    cin>>rollno;
  }

  void display()
  { int i, flag=0, sum=0;
    cout<<"\n\nConsolidated report: ";
    cout<<"\nName: ";
    puts(name);
    cout<<"\nRoll No: "<<rollno;
    cout<<"\nMarks: ";
    for(i=0; i<5; i++)
    {
      cout<<"\nSubject "<<i+1<<" : ";
      if(marks[i] == -1)
        { flag = 1; cout<<"Not yet declared"; }

        else
          { cout<<marks[i];
            sum += marks[i];
          }
    }
    if(flag==0)
    {
      float avg = (float)(sum)/5;
      cout<<"\nPercentage : "<<avg;
    }
  }

  void entermarks(int subcode, int m)
  {
    marks[subcode] = m;
  }
};

#endif
