#include "task5.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,p;
  double temp;
  vector<vector<double>> original;
  vector<vector<double>> eigen_vectors;
  vector<double> eigen_values;
  cin>>n>>p;
  for(int i=0;i<n;i++)
  {
    vector<double> row;
    for(int j=0;j<n;j++)
    {
      cin>>temp;
      row.push_back(temp);
    }
    original.push_back(row);
  }
  task5 t(n,p,original);
  t.eigen_calculator(eigen_vectors,eigen_values);
  cout<<"eigen_vectors"<<endl;
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<p;j++) cout<<eigen_vectors[i][j]<<" ";
    cout<<endl;
  }
  cout<<"eigen_values"<<endl;
  for(int i=0;i<p;i++) cout<<eigen_values[i]<<" ";
  cout<<endl;
  return 0;
}
