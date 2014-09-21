#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>


using namespace std;

int main()
{int a;
  vector<int> input;
  vector<vector<int> > mat1;
  vector<vector<int> > mat2;
  vector<vector<int> > mat3;

  int rm1;
  int cm1;
  int rm2;
  int cm2;
  string s;
  
  while(getline(cin,s))
    { a=atoi(s.c_str());
      input.push_back(a);
    }
  rm1=input.at(0);
  cm1=input.at(1);
  rm2=input.at(2);
  cm2=input.at(3);
  if(cm1!=rm2)
    { printf("Illegal size of matrix for multiplication. Please enter correct dimensions and retry \n");
      return 1;
    }

  input.erase(input.begin(),input.begin()+4);
  mat1.resize(rm1);
  mat2.resize(rm2);
  mat3.resize(rm1);
  int k=0;
  for(int i=0;i<rm1;i++)
    {for(int j=0;j<cm1;j++)
	mat1[i].push_back(input[k++]);
    }

  int m=rm1*cm1;
  
  for(int i=0;i<rm2;i++)
    {for(int j=0;j<cm2;j++)
	mat2[i].push_back(input[m++]);
    }



  for(int i=0;i<rm1;i++)
    {for(int j=0;j<cm1;j++)
	{cout<<" "<<mat1[i][j];
	}
      cout<<endl;
    }
  cout<<endl;

  for(int i=0;i<rm2;i++)
    {for(int j=0;j<cm2;j++)
	{cout<<" "<<mat2[i][j];
	}
      cout<<endl;
    }


  return 0;
}
