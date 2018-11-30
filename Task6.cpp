#include "SymmetricMatrix.h"
#include "Matrix.h"
#include "Record.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>

using namespace std;

void Record::setFeatureVector(vector<double> _newFeatureVector){
    _featureVector = _newFeatureVector;
}

void Matrix::addRecord(Record r) {
    _data.push_back(r);
}


double SymmetricMatrix::get_matrix_element(int i, int j){
    vector<double> feature = getData(i).getFeatureVector();
    return feature[j];
}

vector<int> basicMinDegreeOrdering(vector<int> newPermutedObject, vector<int> permutedObject, SymmetricMatrix &matrixInput){
    if(permutedObject.size() == 1){
        newPermutedObject.push_back(permutedObject[0]);
        return newPermutedObject;
    }
    vector<double> sumOfDegrees;
    int r = matrixInput.getNumRows();
    SymmetricMatrix matrix(r-1);
    for(int i = 0; i < r; i++){
        double flag = 0.0;
        for(int j = 0; j < r; j++){
            if(i != j){
                flag += matrixInput.get_matrix_element(i,j);
            }
        }
        sumOfDegrees.push_back(flag);
    }
    vector<double>:: iterator it;
    it = min_element(sumOfDegrees.begin(), sumOfDegrees.end());
    int in = it - sumOfDegrees.begin();
    for(int i = 0; i < r; i++){
        if(i != in){
            Record record(r-1,0,r-1);
            vector<double> newFeature;
            vector<double> oldFeature = matrixInput.getData(i).getFeatureVector();
            for(int j = 0; j < r; j++){
                if(j != in){
                    newFeature.push_back(oldFeature[j]);
                }
            }
            record.setFeatureVector(newFeature);
            matrix.addRecord(record);
        }
    }
    vector<int> proxyPermutation;
    for(int i = 0; i < r; i++){
			if(i != in){
				proxyPermutation.push_back(permutedObject[i]);
    	}
		}        
    newPermutedObject.push_back(permutedObject[in]);    
    return basicMinDegreeOrdering(newPermutedObject, proxyPermutation, matrix);
}