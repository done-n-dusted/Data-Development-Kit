#include <iostream>
#include <math.h>
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

int Record::getSize()
{
	return feature.size();
}

float Record::euclideanDistance(Record r)
{
	float res = 0;
	float diff = 0;
	for(int i = 0; i < feature.size(); i++)
	{
		diff = feature[i] - r.getFeatureValue(i);
		diff = pow(diff, 2);
		res = res + diff;

	}
	res = pow(res, 0.5);
	return res;
}

void Record::printRecord()
{
	for(int i = 0; i < feature.size(); i++)
	{
		cout << feature[i] << ", ";
	}
	cout << endl;
}

float normalizeValue(float x, float min, float max)
{
    return ((x - min)/(max - min));
}
