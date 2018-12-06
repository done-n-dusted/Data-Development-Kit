#include"RCM_reordering.h"
#include<bits/stdc++.h>
#include<iostream>
#include<string>


SquareMatrix processInput(SquareMatrix matrix, int n)
{
	// SquareMatrix lol(n);
	for(int i = 0; i < n; i++)
	{
        string line;
		stringstream str_strm(line);
		string temp;
		vector<float> res;
		char delim = ',';

		while(getline(str_strm, temp, delim))
		{
			res.push_back(stof(temp));
		}
		for(int j = 0; j < n; j++)
		{
			matrix.setData(i, j, res[i]);
		}
	}
	return matrix;
}


int main(){
    ifstream fin;
    fin.open("./outputs/task2.csv");
    
    if (fin.is_open()){
        string dim; 
        getline(fin, dim);
        SquareMatrix temp(999);
        temp = processInput(temp, 999);
        RCM_reordering lol(temp);
        vector<int> something;
        something = lol.reverse_cuthill();
        cout << "hi\n";
        for(int i=0; i<something.size(); i++)
        {
            cout << something[i];
        }
    }

}