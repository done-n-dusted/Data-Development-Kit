#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;

class Record
{
private:
    vector<float> feature;

public:
    Record(float *, int);
    ~Record();
    Record(const Record&);

    float getFeatureValue(int);
    void setFeatureValue(float, int);
    int getSize();
    float euclideanDistance(Record);
    void printRecord();
};

#endif
