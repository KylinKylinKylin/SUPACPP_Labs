#pragma once
#include <vector>
#include <string>

using namespace std;

bool ReadData(const string&, vector<double>&, vector<double>&);
void Printer(const vector<double>&, const vector<double>&, int&);
vector<double> magnitudes(vector<double>&, vector<double>&);
void BestFit(vector<double>&, vector<double>&, int&);
void Chi_squared(int&, vector<double>&, vector<double>&);