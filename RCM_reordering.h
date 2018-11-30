#ifndef RCM_REORDERING_
#define RCM_REORDERING_ 

#include<iostream>
#include"Matrix.h"
#include"Record.h"
#include<vector>

using namespace std;

class RCM_reordering{
    private:
        SquareMatrix _symSquareMatrix;
        int _dimensions;
    public:
        RCM_reordering(SquareMatrix _symSquareMatrix, int dimensions);
        // ~rcm_reordering();
        void sparsify();
        int max_degree();
        vector<int> reverse_cuthill();
};
#endif
