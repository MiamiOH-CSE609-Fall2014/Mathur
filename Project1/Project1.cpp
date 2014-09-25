#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>


using namespace std;

int main()
{int a;
  
//initializing vectors for input matrices and output matrix
  vector<int> input;
  vector<vector<int> > mat1;
  vector<vector<int> > mat2;
  vector<vector<int> > mat3;

  int rm1;
  int cm1;
  int rm2;
  int cm2;
  string s;
  
while(getline(cin,s)) // taking the input from a text file in the standard input format
    { a=atoi(s.c_str());
      input.push_back(a);
    }
  rm1=input.at(0); // row of matrix1
  cm1=input.at(1); // column of matrix1
  rm2=input.at(2); // row of matrix2 
  cm2=input.at(3); // column of matrix2
  if(cm1!=rm2) //verify of no. of columns in matrix 1 is equal to no of columns in matrix 2
    { printf("Illegal size of matrix for multiplication. Please enter correct dimensions and retry \n");
      return 1;
    }

if( (rm1||cm1||rm2||cm2)==0) //verifying that the size of matrix is not zero..if yes then exiting the code
{ printf("Enter valid size of matrix \n");
return 1;
}
 	
  input.erase(input.begin(),input.begin()+4); // pop out the first four values from the input vector

  mat1.resize(rm1); //resizing matrix for the dynamic input size and expected output size of matrices
  mat2.resize(rm2);
  mat3.resize(rm1);

  int k=0;
  for(int i=0;i<rm1;i++)
    {for(int j=0;j<cm1;j++)
	mat1[i].push_back(input[k++]); //put the input in mat1
    }

  int m=rm1*cm1;
  
  for(int i=0;i<rm2;i++)
    {for(int j=0;j<cm2;j++)
	mat2[i].push_back(input[m++]); //put the input in mat2
    }



  for(int i=0;i<rm1;i++)
    {for(int j=0;j<cm1;j++)
	{cout<<" "<<mat1[i][j]; //printing mat1
	}
      cout<<endl;
    }
  cout<<endl;

  for(int i=0;i<rm2;i++)
    {for(int j=0;j<cm2;j++)
	{cout<<" "<<mat2[i][j]; //printing mat2
	}
      cout<<endl;
    }
cout<<endl;
int n=0;
  for(int i=0;i<rm1;i++)

	{for (int j=0;j<cm2;j++)
 	
		{for (int k=0;k<cm1;k++)
		{
		n+=mat1[i][k]*mat2[k][j]; // multiplying the 2 matrices		
		}
		mat3[i].push_back(n); //pushing the values in mat3 which stores product
		
		n=0;
		
		}	
	}	
	
for(int i=0;i<rm1;i++)
    {for(int j=0;j<cm2;j++)
        {cout<<" "<<mat3[i][j]; //printing out the product matrix
        }
      cout<<endl;
    }
  cout<<endl;
return 0;
}
