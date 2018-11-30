#include"RCM_reordering.h"
#include"Matrix.h"
#include<queue>
#include<vector>

RCM_reordering::RCM_reordering(SquareMatrix m, int dims): _symSquareMatrix(m), _dimensions(dims){}

void RCM_reordering::sparsify(){
    for(int i=0; i<_dimensions; i++){
        for(int j=0; j<_dimensions; j++){
            if(_symSquareMatrix[i][j] < 0.75){
                _symSquareMatrix[i][j] = 0;
            }
            else{
                _symSquareMatrix[i][j] = 1;
            }
        }
    }
}

int RCM_reordering::max_degree(){
    int index = -1;
    int max = -1;
    for(int i=0; i<_dimensions; i++){
        int count =0;
        for(int j=0; j<_dimensions; j++){
            count += _symSquareMatrix[i][j];
        }
        if (count > max){
            index = i;
            max = count;
        }
    }
    return index;
}

vector<int> RCM_reordering::reverse_cuthill(){
    queue<int> Q;
    vector<int> R;
}   

