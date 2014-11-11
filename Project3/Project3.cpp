// Project 3 
// Tushar Mathur, CSE 609, mathurt2@miamioh.edu

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

tuple <string, vector<string>, string> parseFastaFile(const char* filename)
{string h;
  vector<string> c;
  string seq;
  string line;
  ifstream datafile(filename);

    if(datafile.is_open())
      {while(getline(datafile,line))
	  {string temp(">");
	    string temp1(";");

	    size_t found = line.find(temp);
	    size_t found1 = line.find(temp1);
	    
	    if (found!=string::npos) 
	      h=line;

	    else if(found1!=string::npos)
	      c.push_back(line);

	    else
	      seq+=line;
	  }
      
auto tup= make_tuple(h,c,seq);
return tup;
      }
    else
      {cerr << "No such file is available in this location, please re-run" << endl;
	exit (EXIT_FAILURE);
      }
}




int main()
{
  string file;
  cout<<"Enter the file-name with it's path"<<endl;
  cin>>file;

  tuple <string, vector<string>, string> Fasta=parseFastaFile(file.c_str());
}
