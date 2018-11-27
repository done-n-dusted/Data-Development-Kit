#include <iostream>
#include "Matrix.h"
#include "Record.h"

Matrix::Matrix(int r, int c)
{
	nRows = r;
	nColumns = c;

	data = new float*[nRows];
	for(int i = 0; i < nColumns; i++) new float[nColumns];
}

Matrix::~Matrix()
{
	delete [] data;
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

SquareMatrix::SquareMatrix(int n) : Matrix(n, n){};

Record::Record(float *rec, int size)
{
	for(int i = 0; i < size; i++)
	{
		feature.push_back(rec[i]);
	}
}

Record::~Record()
{
	feature.clear();
}

Record::Record(const Record& r)
{
	for(int i = 0; i < r.feature.size(); i++)
	{
		feature.push_back(r.feature[i]);
	}
}

float Record::getFeatureValue(int idx)
{
	return feature[idx];
}

void Record::setFeatureValue(float value, int idx)
{
	feature[idx] = value;
}
