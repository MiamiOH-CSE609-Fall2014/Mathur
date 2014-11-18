// Project 3 
// Tushar Mathur, CSE 609, mathurt2@miamioh.edu

#include <iostream>
#include <stdio.h>
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


map <string,int > digramFreqScores(string s)
{string dgm[] = {"AA", "AG", "AC", "AT", "GA", "GG", "GC", "GT", "CA", "CG", "CC", "CT", "TA", "TG", "TC", "TT"};
  map <string, int> score;
  
  for(int j=0;j<16;j++)
    {int n=0;
      for(int i=0;i<s.length()-1;i++)
    {
      if(s.substr(i,2) == dgm[j])
	{ n+=1;
	}
    }
      score[dgm[j]]=n;
    }
  return score;
}

vector <vector<int> > diagramFreqMatrix(map <string,int> d)
{ string dgm[] = {"AA", "AG", "AC", "AT", "GA", "GG", "GC", "GT", "CA", "CG", "CC", "CT", "TA", "TG", "TC", "TT"};
  int n=0;
  vector <int> col;
  vector <vector<int> > m;
  for(int j = 0; j < 16; j++)
    {col.insert(col.end(),d[dgm[j]]);
    n++;
    if(n == 4)
      {m.insert(m.end(),col);
      col.clear();
      n=0;
      }
    }
  return m;
}

vector <vector<int>> parseScoringFile(const char* filename) 
{ifstream datafile(filename);
 string line;
 vector < vector<int> > scoreMat(5,vector<int>(4));  
if(datafile.is_open())
  {
  for (int j = 0; j < 4; j++) 
    {getline(datafile,line);
    for (int i = 0; i < 4; i++)
      {scoreMat[j][i] = atoi(line.substr(0,1).c_str());
      if (i!=3) 
	line = line.substr(line.find(",")+1);
      }
    }
  return scoreMat;
  }
  else 
  {cerr << "No such file is available in this location, please re-run" << endl;
    exit (EXIT_FAILURE);
  }
}


tuple<int,int> scoreSequence(string haystack,string needle, vector<vector<int>> scoring_m) 
{ string substring;
  map<char,int> ranks = {{'A',0},{'G',1},{'C',2},{'T',3}};
  size_t hl= haystack.length(),nl= needle.length();
  int highScore = 0,ix = 0, tempScore=0;  
for (int i = 0; i < hl-nl+1; i++) 
  { tempScore = 0;
    substring = haystack.substr(i,needle.length());
    
    for (int j = 0; j < nl; j++) 
      tempScore+=scoring_m[ranks[substring[j]]][ranks[needle[j]]];
      
    if(highScore<tempScore) 
    {ix=i;
     highScore = tempScore;
    }
  }
  return make_tuple(ix,highScore);
}




tuple<int, int, string> findHighScore(string haystack, vector<string> needles, vector<vector<int>> scoring_m)
{
  tuple <int, int, string> high_score_tup;
  // cout<<"inside findHighScore 0"<<endl;
  tuple <int, int> temp_scoreSeq;
  temp_scoreSeq= scoreSequence(haystack, needles[0], scoring_m); 
  
  //cout<<"inside findHighScore 1"<<endl;

  get<0>(high_score_tup) = get<0>(temp_scoreSeq);
  //cout<<"inside findHighScore 2"<<endl;
  get<1>(high_score_tup) = get<1>(temp_scoreSeq);
  get<2>(high_score_tup) = needles[0];
  //cout<<"inside findHighScore"<<endl;
  for(int i = 1; i < needles.size(); ++i)
{ temp_scoreSeq = scoreSequence(haystack, needles[i], scoring_m);
  if(get<1>(temp_scoreSeq) > get<1>(high_score_tup))
    { get<0>(high_score_tup) = get<0>(temp_scoreSeq);
	get<1>(high_score_tup) = get<1>(temp_scoreSeq);
	get<2>(high_score_tup) = needles[i];
    }
  }
  //cout<<"returning high score"<<endl;
  return high_score_tup;
}





int main(int argc, char** argv)
{if(argc!=3)
    { cerr<<"You have not entered sufficient arguments, program will EXIT"<<endl;
      exit (EXIT_FAILURE);
    }
  
string dgm[] = {"AA", "AG", "AC", "AT", "GA", "GG", "GC", "GT", "CA", "CG", "CC", "CT", "TA", "TG", "TC", "TT"};
  //string file;
  //cout<<"Enter the file-name with it's path"<<endl;
  //cin>>file;

 tuple <string, vector<string>, string> Fasta=parseFastaFile(argv[1]);

  map< string, int > score = digramFreqScores(get<2>(Fasta));

  map<string,int>::iterator it;
  cout << "Score contains:\n";
  for (it=score.begin(); it!=score.end(); ++it)
    {cout << it->first << " => " << it->second << '\n';
    }

  vector< vector<int> > dfm= diagramFreqMatrix(score);
  cout<<'\n';
  
  cout<<'\t'<<"Diagram Frequency Matrix \n"<<endl;
  cout<<'\t'<<"   A  "<<"G  "<<"C  "<<"T  "<<endl;
  string l [4] = {"A","G","C","T"};

  for(int i = 0; i < 4; i++) 
    {for (int j = 0; j < 4; j++) 
	{if (j==0 & i == 0) 
	    {printf("       %s  %d ",l[i].c_str(),dfm[i][j]);
	    }
	  else if (j == 0) 
	    {printf("\n       %s  %d ",l[i].c_str(),dfm[i][j]);
	    }
	  else 
	    {printf("%d ", dfm[i][j]);
	    }
	}
    }
  cout<<"\n"<<endl;
  //cout<<"Enter the scoring file-name with it's path"<<endl;
  //cin>>file;

  vector<vector<int>> score_mat = parseScoringFile(argv[2]);

  cout<<"\n \tScoring Matrix \n"<<endl;
  cout<<"\t  A"<<" G"<<" C"<<" T"<<endl;


  for(int j = 0; j < 4; j++) 
    {for (int i = 0;  i< 4; i++) 
      
      {if (i==0 & j == 0)
	  {printf("       %s  %d ",l[j].c_str(),score_mat[j][i]);
	  }
	else if (i == 0)
	  {printf("\n       %s  %d ",l[j].c_str(),score_mat[j][i]);
	  }
	else
	  {printf("%d ", score_mat[j][i]);
	  }
      }
    }

  cout<<"\n"<<endl;

  int num_seq;
  vector<string> seqs;
  string lines;
  cout << "How many sequences would you like to score? ";
  cin >> num_seq;
  cout << "Enter your sequences: " << endl;
  for(int i = 0; i < num_seq; i++)
    {
      cin >> lines;
      seqs.push_back(lines);
    }
  string sequence = get<2>(Fasta);
  //cout<<"before entering findhighscore func"<<endl;
  tuple<int, int, string> highestScorer = findHighScore(sequence, seqs, score_mat);
  cout << "\nScoring Sequence: " << get<2>(highestScorer)<<endl; 
  cout << "Highest Score of Sequence: " << get<1>(highestScorer)<<endl;
  cout << "Position of Highest Score Sequence: " << get<0>(highestScorer) << endl; 
  cout <<"\n";
  return 0;
}
