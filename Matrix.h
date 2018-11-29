#ifndef MATRIX_H
#define MATRIX_H
#include "Record.h"
#include <iostream>

using namespace std;

class Matrix
{
private:
    int nRows, nColumns;
    //float **data;
		vector<Record> _data;

public:
    Matrix(int, int);
    // ~Matrix();
    Matrix(const Matrix&);
    void setData(int, int, float);
    void printMatrix();
    //float getData(int i, int j);
		Record getData(int i){ return _data[i];}
		int getNumRows(){return nRows;}
		void addRecord(Record r);
};


/*class SquareMatrix : public Matrix
{
private:
    int n;

public:
    SquareMatrix(int);
};*/

#endif
