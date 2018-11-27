#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
private:
    int nRows, nColumns;

protected:
    float **data;

public:
    Matrix(int, int);
    ~Matrix();
    Matrix(const Matrix&);

    void setData(int, int, float);
};


class SquareMatrix : public Matrix
{
private:
    int n;

public:
    SquareMatrix(int);
};

#endif
