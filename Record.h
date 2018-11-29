#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;

class Record
{
private:
    vector<string> feature;
    float eucDis, normalVal;

public:
    Record();
    Record(vector<string>);
    ~Record();
    Record(const Record&);

    string getFeatureValue(int);
    void setFeatureValue(string, int);
    void setNormal(float);
    float getNormal();
    float getEuc();
    void setEuc(float);
    int getSize();
    float euclideanDistance(Record, int);
    void printRecord();
};

#endif
