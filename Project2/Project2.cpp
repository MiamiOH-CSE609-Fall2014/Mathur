#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cctype>
#include<math.h>


using namespace std;

string name;
string g;  
double grade;
vector<double> gradedb;
vector<string> namedb;
vector<char> lgrades;
double avg=0.0;
double stdev=0.0;
double A=0.0;
double B=0.0;
double C=0.0;
double D=0.0;


void NameAndGradeDB() //function for entering name and grade to the data base

{int r=1;

  while(r)
  { cout << "Please enter a student’s first and last name or ‘NONE’ to quit \n";
    getline(cin,name);

    while(find_if(name.begin(),name.end(),(int(*)(int))isdigit)!=name.end())
      {printf("invalid input, enter a string \n"); //check to see if the input was a string and not a numerical value
	getline(cin,name);
       continue;
      } 
   
    if (name=="NONE" || name="none" || name="None")
      r=0; //will exit from the loop
    
    if(name.empty()) //check to see if a blank was inserted
      { cout<<"you entered a blank space, please enter a name"<<endl;
	getline(cin,name);
	if(find_if(name.begin(),name.end(),(int(*)(int))isdigit)!=name.end())
	  {printf("invalid input, enter a string \n");
	    getline(cin,name);
	  }
      }
    namedb.push_back(name);
  
    cout<<"Please enter the grade of student \n";
    getline(cin,g);
    grade=atof(g.c_str());
    while(g.empty() || grade<0.00 || grade>100.00) 
      {cout<<"Invalid range of grades. Please re-enter grade"<<endl;
	getline(cin,g);
	grade=atof(g.c_str());
	continue;
      }
    gradedb.push_back(grade);  
}
}


void av_me_gscale()
{ vector<double>::size_type gradedb_sz = gradedb.size();
  for(int j=0;j<gradedb_sz;j++)
    avg+=avg/gradedb[j]; //calculating the average

  avg=avg/gradedb_sz();

  for(j=0;j<gradedb_sz;j++)
    stdev+=pow((gradedb[i]-avg),2);

  stdev=pow((dev/gradedb_sz),1/2));//calculating the stdev

  A = (1.5*stdev)+avg;
  B = (0.5*stdev)+avg;
  C = (-0.5*stdev)+avg;
  D = (-1.5*stdev)+avg;

printf("\n****Grading scale****\n");

if(A>100)
  printf("A above 100.0% \n");
 else
   printf("A above %.1f% \n", A);

printf("B %.1f% - %.1f% \n", B, A);
printf("C %.1f% - %.1f% \n", C, B);
printf("D %.1f% - %.1f% \n", D, C);
printf("F below %.1f%  \n\n",D);
}



