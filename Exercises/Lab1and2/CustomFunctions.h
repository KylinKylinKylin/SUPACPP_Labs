#pragma once
#include <vector>
#include <string>


using namespace std;

bool ReadData(const string&, vector<double>&, vector<double>&);

template <typename A, typename B, typename C>
void Printer(const vector<A>& x, const vector<B>& y, C& N){
    if (x.empty() || y.empty()) {
        cout << "Input vectors are empty try again!" << endl;
        return;
    }

    // error if too large prints first 5 lines
    if (N > x.size() || N > y.size()) {
        cout << "The number you entered exceeds the length of the data file. Enter a number smaller than " << N << endl;
        cout << "Printing the first 5 lines..." << endl << endl;
        N = 5;
    }

    // Printing the number of lines for x and y
    cout << "The x values are: " << endl;
    for (int i=0; i<N; i++) {
        cout << x[i] << endl;
    }
    cout << "The y values are: " << endl;
    for (int i=0; i<N; i++) {
        cout << y[i] << endl;
    }
}
template <typename T>
void Printer(T& input);


vector<double> magnitudes(vector<double>&, vector<double>&);
void BestFit(vector<double>&, vector<double>&, int&);

