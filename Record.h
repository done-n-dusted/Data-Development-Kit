#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;

class Record
{
private:
    vector<string> feature;
    int idx;
    float eucDis, normalVal;

public:
    Record();
    Record(vector<string>);
    ~Record();
    Record(const Record&);

    string getFeatureValue(int);
    void setFeatureValue(string, int);
    int getIndex() const;
    void setIndex(int);
    void setNormal(float);
    float getNormal() const;
    float getEuc();
    void setEuc(float);
    int getSize();
    float euclideanDistance(Record, int);
    void setIndx(int);
    void printRecord() const;

    // friend bool operator < (const Record&, const Record&);
};

#endif
