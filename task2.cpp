#include "Matrix.h"
#include "Record.h"
#include <bits/stdc++.h>
#define INF 99999;

using namespace std;

float normalizeValue(float x, float min, float max)
{
    return ((x - min)/(max - min));
}

bool compare(Record r1, Record r2)
{
    // cout << "#\n";
    return r1.getNormal() >= r2.getNormal();
}

vector<string> parseLine(string line)
{
    stringstream str_strm(line);
    string temp;
    vector<string> res;
    char delim = ',';

    while(getline(str_strm, temp, delim))
    {
        res.push_back(temp);
    }
    return res;
}

Record createAvgRecord(vector<Record> recs, int thre)
{
    vector<string> res;
    for(int i = 0; i < thre; i++)
    {
        res.push_back("x");
    }

    float avg;
    for(int j = thre; j < recs[0].getSize(); j++)
    {
        for(int i = 0; i < recs.size(); i++)
        {
            avg = avg + stof(recs[i].getFeatureValue(j));
        }
        avg = avg/recs.size();
        string s = to_string(avg);
        res.push_back(s);
    }
    // res.pop_back();

    return Record(res);
}
int main()
{
    ifstream fin;
    fin.open("./datasheets/sample.csv");
    vector<Record> records;
    string line,lin1;
    getline(fin, line);
    cout << "#\n";
    line = line + "\n";
    int count  = 0;
    vector<string> titles = parseLine(line);
    while(fin)
    {
        getline(fin, line);
        line = line + "\n";
        vector<string> lol = parseLine(line);
        Record temp(lol);
        records.push_back(lol);
    }
    records.pop_back();
    Record hypAvg = createAvgRecord(records, 4);
    float max = 0 - INF
    float min = INF;
    for(int i = 0; i < records.size(); i++)
    {
        float e = records[i].euclideanDistance(hypAvg, 4);
        cout << e << endl;
        records[i].setEuc(e);
        if(max <= e)    max = e;
        if(min >= e)    min = e;
    }
    cout << "# " << max << " " << min << endl;
    for(int i = 0; i < records.size(); i++)
    {
        float n = normalizeValue(records[i].getEuc(), min, max);
        cout << n << endl;
        records[i].setNormal(n);
    }

    sort(records.begin(), records.end(), compare);

    for(int i = 0; i < records.size(); i++)
    {
        cout << records[i].getEuc();
        cout << endl;
    }
    /*
    Matrix output = Matrix(records.size(), records.size());
    for(int i = 0; i < records.size(); i++)
    {
        for(int j = i + 1; j < records.size(); j++)
        {
            // cout << ":" << i << " " << j << endl;
            // if(i == j)  output.setData(i, j, 0);
            if(i != j)
            {
                float f = records[i].euclideanDistance(records[j], 4);
                output.setData(i, j, f);
                output.setData(j, i, f);
            }
        }
    }

    // output.printMatrix();
    */
    return 0;
}
