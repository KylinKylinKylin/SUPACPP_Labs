#pragma once
#include <vector>
#include <string>

using namespace std;

bool ReadData(const string&, vector<double>&, vector<double>&);
void Printer(const vector<double>&, const vector<double>&);
vector<double> magnitudes(vector<double>&, vector<double>&);