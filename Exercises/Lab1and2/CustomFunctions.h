#pragma once
#include <vector>
#include <string>
#include <utility>


using namespace std;

bool ReadData(const string&, vector<double>&, vector<double>&);


void Printer(const vector<double>& x, const vector<double>& y, int& N);
void Printer(const string& input);


vector<double> magnitudes(vector<double>&, vector<double>&);
pair<double, double> BestFit(vector<double>&, vector<double>&, int&);

vector<double> XpY(vector<double>&, vector<double>&);

void Lastfunc(const vector<double>& vec, const string& filename);
void Lastfunc(double p, double q, const string& filename);