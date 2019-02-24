#ifndef CASH_H
#define CASH_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Cash
{
private:
    vector<string> data;
    string path;
public:
    Cash(string path);
    ~Cash();

    void load();
    void save();
    void add(string new_data);
    string get(int elem_id);
};
#endif // CASH_H
