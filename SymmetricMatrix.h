#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H_

#include "Matrix.h"
//Inheriting from Matrix//
class SymmetricMatrix : public Matrix {
    private: 
    public: SymmetricMatrix(int M): Matrix(M,M){}//Calling Constructor of Matrix//
            // SymmetricMatrix(const SymmetricMatrix&);
            // ~SymmetricMatrix();
            double get_matrix_element(int i,int j);
};

#endif
