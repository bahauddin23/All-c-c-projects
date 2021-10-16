#include<iostream>
#include<fstream>
#include<stdio.h>
#include "admin.h"
#include "teacher.h"
#include "student.h"

using namespace std;

admin ad;

int main()
{
  fstream fs, f;

  cout<<"\n\nWelcome to Student Result System";
  int opt=0, subopt=0, id, found=0;

  student St;

  while(opt!=4)
  {
    cout<<"\n\nMenu:\n1. Admin\n2. Teacher: Update Marks\n3. Student: Check Results\n4. Exit\n\nEnter option: ";
    cin>>opt;

    switch(opt)
    {
      case 1: cout<<"\n\nSub Menu:\n1. Add teacher\n2. Add student\n\nEnter option: ";
              cin>>subopt;
              switch(subopt)
              {
                case 1: ad.addteacher();
                        break;
                case 2: ad.addstudent();
                        break;
                default: cout<<"\n\nInvalid choice";
                         break;
              }
              break;

      case 2: cout<<"\n\nEnter teacher id: ";
              cin>>id;

              f.open("teacher.dat", ios::in);
              teacher T;  found = 0;

              while(!f.eof()&&found==0)
              {
                f.read((char*)&T, sizeof(T));

                if(T.idcompare(id))
                { T.updateMarks();
                  found=1;
                }
              }

              if(found == 0)
                cout<<"\n\nInvalid ID";

              f.close();
              break;

      case 3: cout<<"\n\nEnter student roll no: ";
              cin>>id;

              fs.open("student.dat", ios::in);
              found = 0;

              while(!fs.eof()&&found==0)
              {
                fs.read((char*)&St, sizeof(St));

                if(id == St.getroll())
                { St.display();
                  found=1;
                }
              }

              if(found == 0)
                cout<<"\n\nInvalid roll number";

              fs.close();
              break;

      case 4: return 0;

      default: cout<<"\n\nInvalid choice";
               break;
    }

  }

 return 0;
 }
