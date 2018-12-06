#include "task5.h"
#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

vector<string> parseLine(string line)
{
    stringstream str_strm(line );
    string temp;
    vector<string> res;
    char delim = ',';
    while(getline(str_strm, temp, delim))
    {
        res.push_back(temp);
    }
    return res;
}

int main()
{
  int n,p;
  char x;
  double temp;
  string line;
  vector<vector<double>> original;
  vector<vector<double>> eigen_vectors;
  vector<double> eigen_values;
  ifstream fin;
  ofstream fout;
  fin.open("./outputs/task2.csv");
  fout.open("output.txt");
  while(fin)
  {
    getline(fin, line);
    vector<string> lol = parseLine(line);
    vector<double> double_vector;
    if(lol.size()==2)
    {
      n = stod(lol[0]);
      p = stod(lol[1]);
    }
    else if(lol.size()==n)
    {
      for(int i=0;i<n;i++) double_vector.push_back(stod(lol[i]));
      original.push_back(double_vector);
    }
  }
  p = 10;
  task5 t(n,p,original);
  t.eigen_calculator(eigen_vectors,eigen_values);
  fout<<"eigen_vectors"<<endl;
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<p;j++) fout<<eigen_vectors[i][j]<<" ";
    cout<<endl;
  }
  fout<<"eigen_values"<<endl;
  for(int i=0;i<p;i++) fout<<eigen_values[i]<<" ";
  cout<<endl;
  return 0;
}
