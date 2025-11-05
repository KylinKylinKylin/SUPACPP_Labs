#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// Custom functions file used in AnalyseData.cpp

// Reads an input file and returns the contents into a vector of x and y
bool ReadData(const string& inputfile, vector<double>& x, vector<double>& y) {

    // opens the file
    ifstream data_file(inputfile);

    // error output if file cannot be openned
    if (!data_file.is_open()) {
        cerr << "Error cannot open the file!";
        return 1;
    }

    // Reading each line of the file and separating it into the x and y vectors
    string line;

    while (getline(data_file, line)) {
        stringstream ss(line);
        string xStr, yStr;

        if (getline(ss, xStr, ',') && getline(ss, yStr, ',')) {
            try {
                double xVal = stod(xStr);
                double yVal = stod(yStr);
                
                // Push back into vectors
                x.push_back(xVal);
                y.push_back(yVal);
            } catch (const invalid_argument&) {
                cerr << "Invalid number in line -> " << line << endl;
            }
        }
    }
    data_file.close();
    return 0;
}

// Second functions takes filled vectors x and y and prints the asked amount to the terminal

void Printer(const vector<double>& x, const vector<double>& y) {
    if (x.empty() || y.empty()) {
        cout << "Input vectors are empty try again!" << endl;
        return;
    }

    int N;
    cout << "Enter the number of lines from the data file you want to be printed to the terminal: ";
    cin >> N;

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

vector<double> magnitudes(vector<double>& x, vector<double>& y) {
    // intialize magnitudes vector
    vector<double> mag;

    // loop to calculate the magnitude and push into the mag vector
    for (int i=0; i<x.size(); i++) {
        double A = sqrt(pow(x[i], 2) + pow(y[i], 2));
        mag.push_back(A);
    }
    return mag;
}