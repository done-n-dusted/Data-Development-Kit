#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H
#include "Matrix.h"
#include<iostream>

using namespace  std;

class symmetricMatrix:public Matrix{
    public:
        symmetricMatrix(int M):Matrix(M,M){};
};
#endif
