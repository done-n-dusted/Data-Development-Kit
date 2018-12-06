#include <iostream>
#include <math.h>
#include "Matrix.h"


Matrix::Matrix(int r, int c)
{
	cout << r << " " << c << endl;
	nRows = r;
	nColumns = c;
	data = new float*[nRows];
	for(int i = 0; i < nRows; i++)
	{
		data[i] = new float [nColumns];
		for(int j = 0; j < nColumns; j++)
		{
			// cout << ": " << i << " " << j << endl;
			data[i][j] = 0;
		}
	}
}
/*
Matrix::~Matrix()
{
	delete [] data;
}
*/

int Matrix::getNoRows(){
	return nRows;
}

int Matrix::getNoCols(){
	return nColumns;
}

void Matrix::setData(int i, int j, int val){
	data[i][j] = val;
}
Matrix::Matrix(const Matrix& m)
{
	nRows = m.nRows;
	nColumns = m.nColumns;

	data = new float*[nRows];
	for(int i = 0; i < nColumns; i++) new float[nColumns];
}

void Matrix::setData(int i, int j, float x)
{
	data[i][j] = x;
}

float Matrix::getData(int i, int j)
{
	return data[i][j];
}

void Matrix::printMatrix()
{
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 0; j < nColumns; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}



