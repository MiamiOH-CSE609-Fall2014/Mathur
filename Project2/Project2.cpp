#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cctype>
#include<math.h>
#include<iomanip>
#include<limits>

using namespace std;

string name;
string g;  
double grade;
vector<double> gradedb;
vector<string> namedb;
vector<char> lgrades;
double sum=0.0;
double avg=0.0;
double stdev=0.0;
double A=0.0;
double B=0.0;
double C=0.0;
double D=0.0;


vector<double>::size_type gradedb_sz = 0;


int len_func(int i)
{int len = 1;

  if (i > 0)
    { for (len = 0; i > 0; len++)
	{i = i / 10;
	}
    }
return len;
}



void NameAndGradeDB() //function for entering name and grade to the data base

{int r=1;

  while(r)
  { cout << "Please enter a students first and last name or NONE to quit \n";
    getline(cin,name);
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (name.empty()) //check to see if a blank was inserted
      { cout<<"you entered a blank space, please enter a name"<<endl;
        getline(cin,name);
        if(find_if(name.begin(),name.end(),(int(*)(int))isdigit)!=name.end())
          {printf("invalid input, enter a string \n");
            getline(cin,name);
          }
      }


     while(find_if(name.begin(),name.end(),(int(*)(int))isdigit)!=name.end())
      {printf("invalid input, enter a string \n"); //check to see if the input was a string and not a numerical value
	getline(cin,name);
       continue;
      } 
    

    if (name=="NONE" || name=="none" || name=="None")
      {r=0; return;
      } //will exit from the loop

    namedb.push_back(name); //adding name to the name data base
  
    

    cout<<"Please enter the grade of student \n";
    getline(cin,g);
        
    grade=atof(g.c_str()); //changing string to double

    if(g.empty() || grade<0.00 || grade>100.00) 
      {cout<<"Invalid range of grades. Please re-enter grade"<<endl;
	getline(cin,g);
	grade=atof(g.c_str());
      }

    gradedb.push_back(grade);  //adding grade to the grade data base
  
          
      
  }
}


void av_me_gscale()
{ gradedb_sz = gradedb.size();
  
  cout<<"gradedb_sz:"<<gradedb.size()-1<<endl;

  for(int j=0;j<gradedb_sz;j++)
    {sum+=gradedb[j]; //calculating the average
    }
  avg=sum/(gradedb_sz);
  cout<<"avg:"<<avg<<endl;



  for(int j=0;j<gradedb_sz;j++)
    {stdev+=pow((gradedb[j]-avg),2);
    }
  stdev=pow((stdev/(gradedb_sz)),0.5);//calculating the stdev
  cout<<"stdev:"<<stdev<<endl;


  A = (1.5*stdev)+avg;
  B = (0.5*stdev)+avg;
  C = (-0.5*stdev)+avg;
  D = (-1.5*stdev)+avg;

printf("\n****Grading scale****\n");

if(A>100)
  printf("A above 100.0%% \n");
 else
   printf("A above %.1f%% \n", A);

printf("B %.1f%% - %.1f%% \n", B, A);
printf("C %.1f%% - %.1f%% \n", C, B);
printf("D %.1f%% - %.1f%% \n", D, C);
printf("F below %.1f%%  \n\n",D);
}


char letter_grade(double n)
{if(n>=A)
    return 'A';
  else if(n<A && n>=B)
    return 'B';
  else if(n<B && n>=C)
    return 'C';
  else  if(n<C && n>=D)
    return 'D';
  else
    return 'F';
}


int main()
{ int k=0;
  NameAndGradeDB();

  if(!namedb.empty())
    {av_me_gscale();


  gradedb_sz = gradedb.size();
    
  k=len_func(gradedb[1]);

  for(int i=0;i<gradedb_sz-1;i++)
    {lgrades.push_back(letter_grade(gradedb[i]));
		       }		  


      cout<<"Name"<<setw(15)<<"Score"<<setw(15)<<"Grade"<<endl;
      vector<double>::size_type namedb_sz = namedb.size();

  for(int i=0;i<namedb_sz;i++)
    {cout<<i+1<<"."<<left<<namedb[i]<<setw(15)<<right<<setprecision(k+1)<<gradedb[i]<<setw(15)<<right<<lgrades[i]<<endl;
    }

  k=len_func(avg);
  cout<<setw(15)<<"Class Average ="<<setprecision(k+2)<<avg<<endl;
  cout<<"Standard Deviation ="<<setprecision(k+2)<<stdev<<endl;
    }
  
  else {cout<<"database is empty, exiting the application"<<endl;
      return 1;}
  return 0;
}
    
