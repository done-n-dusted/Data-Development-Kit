SquareMatrix processInput()
{
	SquareMatrix lol(n);
	for(int i = 0; i < n; i++)
	{
		stringstream str_strm(line);
		string temp;
		vector<string> res;
		char delim = ',';

		while(getline(str_strm, temp, delim))
		{
			res.push_back(stof(temp));
		}
		for(int j = 0; j < n; j++)
		{
			lol.setData(i, j, res[i]);
		}
	}
	return lol;
}
