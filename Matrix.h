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
    int getNoRows();
    int getNoCols();
    float getData(int, int);
    void setData(int i , int j, int value);

    friend ostream& operator << (ostream& mos, Matrix &m);
};


#endif