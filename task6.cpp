#include <iostream>
#include "SymmetricMatrix.h"
#include "Matrix.h"
#include <vector>
#include <algorithm> 
#include <iterator>

using namespace std;
vector<int> basicMinDegreeOrdering(vector<int> newPermutedObject, vector<int> permutedObject, symmetricMatrix &matrixInput){
    if(permutedObject.size() == 1){
        newPermutedObject.push_back(permutedObject[0]);
        return newPermutedObject;
    }
    vector<double> sumOfDegrees;
    int r = matrixInput.getNoRows();
    symmetricMatrix matrix(r-1);
    for(int i = 0;i < r;i++){
        double flag = 0.0;
        for(int j = 0;j < r;j++){
            if(i != j){
                flag += matrixInput.getData(i,j);
            }
        }
        sumOfDegrees.push_back(flag);
    }
    vector<double>::iterator it;
    it = min_element(sumOfDegrees.begin(),sumOfDegrees.end());
    int in = it - sumOfDegrees.begin();
    vector<float> submatar;
    for(int i = 0;i < r;i++){
        if(i != in){
            for(int j = 0;j < r;j++){
                if(j != in){
                    submatar.push_back(matrixInput.getData(i,j));
                }
            }   
        }
    }
    for(int i = 0;i < r-1;i++){
        for(int j = 0;j < r-1;j++){
            matrix.setData(i,j,submatar.at(2*i+j));
        }
    }
    vector<int> proxyPermutation;
    for(int i = 0;i < r;i++){
        if(i != in){
            proxyPermutation.push_back(permutedObject[i]);
        }
    }
    newPermutedObject.push_back(permutedObject[in]);
    return  basicMinDegreeOrdering(newPermutedObject,proxyPermutation,matrix);
}
int main(){
    int row = 3;
    float num1 = 0.0;
    float num2 = 1.4;
    float num3 = 1.3;
    float num4 = 1.3;
    float num5 = 0.0;
    float num6 = 1.7;
    float num7 = 1.3;
    float num8 = 1.7;
    float num9 = 0.0;
    symmetricMatrix matrix(row);
    matrix.setData(0,0,num1);
    matrix.setData(0,1,num2);
    matrix.setData(0,2,num3); 
    matrix.setData(1,0,num4);  
    matrix.setData(1,1,num5); 
    matrix.setData(1,2,num6); 
    matrix.setData(2,0,num7); 
    matrix.setData(2,1,num8); 
    matrix.setData(2,2,num9); 
    vector<int> newPermutedObject;
    vector<int> permutedObject;
    for(int i = 0;i < 3;i++){
        permutedObject.push_back(i);
    }
    vector<int> ans = basicMinDegreeOrdering(newPermutedObject,permutedObject,matrix);
    for(int i = 0;i < 3;i++){
        cout<< ans.at(i)<<" ";
    }
    return 0;
}
