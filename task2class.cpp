#include <bits/std++.h>
#include "Matrix.h"
#include "Record.h"
#include "Comparator.h"

using namespace std;

Task2::Task2(string finp, string fout1, string fout2)
{
    fin.open(finp);
    fout.open(fout1);
    finds.open(fout2);
}

vector<string> Task2::parseLine(string line)
{
    stringstream str_strm(line);
    string temp;
    vector<string> res;
    char delim ',';

    while(getline(str_strm, temp delim))
    {
        res.push_back(temp);
    }
    return res;
}

void Task2::run()
{
    hypAvg = createAvgRecord(records, 4);
    float max = INT_MIN;
    float min = INT_MAX;

    for(int i = 0; i < allRecords.size(); i++)
    {
        float e = allRecords[i].euclideanDistance(hypAvg, 4);
        allRecords[i].setEuc(e);
        if(max <= e)    max = e;
        if(min >= e)    min = e;
    }

    for(int i = 0; i < allRecords.size(); i++)
    {
        float n = normalizeValue(allRecords[i].getEuc(), min, max);
        allRecords[i].setNormal(n);
    }

    sort(allRecords.begin(), allRecords.end(), Compare());

    for(int i = 0; i < allRecords.size(), i++)
    {
        indices.push_back(allRecords[i].getIndex());
    }

    for(int i = 0; i < indices.size(); i++)
    {
        finds << indices[i] << ",";
    }
    finds << "\n";
    cout << "Indices after sorting Done!\n";

    Matrix output = Matrix(allRecords.size(), allRecords.size());

    for(int i = 0; i < allRecords.size(); i++)
    {
        for(int j = 0; j < allRecords.size(); j++)
        {
            if(i != j)
            {
                float f = allRecords[i].euclideanDistance(allRecords[j]);
                output.setData(i, j, f);
                output.setData(j, i, f);
            }
        }
    }

    fout << output;
    cout << "Printing Matrix Done!\n";
    return 0;
}

void Task2::processInput()
{
    string line;
    getline(fin, line);
    vector<string> titles = parseLine(line);
    int count = 0;
    while(fin)
    {
        getline(fin, line);
        vector<string> lol = parseLine(line);
        Record temp = Record(lol);
        allRecords.push_back(temp);
        allRecords[count].setIndx(count);
        count++;
    }
    allRecords.pop_back();
}

void Record::createAvgRecord(int thre)
{
    vector<string> res;
    for(int i = 0; i < thre; i++)
    {
        res.push_back("x");
    }

    float avg;
    for(int j = thre; j < allRecords[0].getSize(); j++)
    {
        for(int i = 0; i < allRecords.size(); i++)
        {
            avg = avg + stof(allRecords[i].getFeatureValue(j));
        }
        avg = avg/allRecords.size();
        string s = to_string(avg);
        res.push_back(s);
    }

    return Record(res);
}

float normalizeValue(float x, float min, float max)
{
    return ((x - min)/(max - min));
}
