#include"RCM_reordering.h"
#include"Matrix.h"
#include<queue>
#include<vector>
#include<bits/stdc++.h>

RCM_reordering::RCM_reordering(SymmetricMatrix m, int dims): _matrix(m){}

RCM_reordering::~RCM_reordering(){
    
}


//copy constructor
RCM_reordering::RCM_reordering(const RCM_reordering &matrix){
   
}


void RCM_reordering::sparsify(){
    for(int i=0; i<_matrix.getNoRows(); i++){
        for(int j=0; j<_matrix.getNoCols(); j++){
            if(_matrix.getData(i, j) < 0.75){
                _matrix.setData(i, j, 0);
            }
            else{
                _matrix.setData(i, j, 1);
            }
        }
    }
}

vector<int> RCM_reordering::Degrees(){
    vector<int> degrees;
    for(int i=0; i<_matrix.getNoRows(); i++){
        int count = 0;
        for(int j=0; j<_matrix.getNoCols(); j++){
            count += _matrix.getData(i, j);
        }
        degrees.push_back(count);
    }
}



vector<int> RCM_reordering::reverse_cuthill(){
    queue<int> Q;
    vector<int> R;
}   

