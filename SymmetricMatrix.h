#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H_

#include "DataMatrix.h"
//Inheriting from Matrix//
class SymmetricMatrix : public DataMatrix {
    private: 
    public: SymmetricMatrix(int M): DataMatrix(M,M){}//Calling Constructor of Matrix//
            // SymmetricMatrix(const SymmetricMatrix&);
            // ~SymmetricMatrix();
            double get_matrix_element(int i,int j);
};

#endif
