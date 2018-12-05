#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
private:
    int nRows, nColumns;
    float **data;

public:
    Matrix(int, int);
    ~Matrix();
    Matrix(const Matrix&);

    void setData(int, int, float);
    void printMatrix();
    float getData(int, int);

    friend ostream& operator << (ostream& mos, Matrix &m);
};


class SquareMatrix : public Matrix
{
private:
    int n;

public:
    SquareMatrix(int);
};

#endif
