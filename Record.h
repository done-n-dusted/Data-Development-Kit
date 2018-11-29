#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;

class Record
{
	private: int _numVariables;
           int _numNonNumericalVariables;
           int _numNumericalVariables;
           vector<string> _nonFeatureVector; 
           vector<double> _featureVector;
    			 float eucDis, normalVal;
public:
    Record(int y, int n, int n1):_numVariables(y), _numNonNumericalVariables(n), _numNumericalVariables(n1) {}
		Record(int, int, int, vector<string>,vector<double>);
    ~Record();
    Record(const Record&);
		vector<double> getFeatureVector(){ return _featureVector; }
    string getFeatureValue(int);
    void setFeatureValue(string, int);
		void setFeatureVector(vector<double> _newFeatureVector);
    void setNormal(float);
    float getNormal();
    float getEuc();
    void setEuc(float);
    int getSize();
    float euclideanDistance(Record, int);
    void printRecord();
};

#endif
