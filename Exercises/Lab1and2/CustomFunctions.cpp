#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <utility>

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

    // Reads through every line in the data file
    // put the lines into 2 different strings to be pushed back into a vector of x and y
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

// Print_to functions to be used in all functions to print to screen using overloading
// Second functions takes filled vectors x and y and prints the asked amount to the terminal
void Printer(const vector<double>& x, const vector<double>& y, int& N) {
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
void Printer(const string& input) {
    cout << input << endl;
}

// Function to calculate a vector of magnitudes outputing as a vector as well
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

// Function that takes in x, y data and fits a straight line to it using least squares method saving as a string to another file

pair<double, double> BestFit(vector<double>& x, vector<double>& y, int& N) {
    // N should be declared from the printer function
    // loop required to determine p and q

    double p, q, xy1, x2, y2, xx1;

    // xy1 is the sum of x_i * y_i
    // x2 is the sum of all x_i
    // y is the sum of all y_i
    // xx1 is the sum of all x_i^2

    // Set all to zero so that if ran twice p and q stay the same
    xy1 = 0;
    x2 = 0;
    y2 = 0;
    xx1 = 0;

    for (int i=0; i<N; i++) {
        xy1 += x[i] * y[i];
        x2 += x[i];
        y2 += y[i];
        xx1 += pow(x[i], 2);
    }

    p = ((N * xy1) - (x2 * y2)) / ((N*xx1) - (x2*x2));
    q = ((xx1 * y2) - (xy1 * x2)) / ((N * xx1) - (x2 * x2));


    // Chi squared function to dermine how good the line is
    // Initialize variable and vectors of errors
    vector<double> xerr, yerr;

    // Reads the error data and outputs the xy errs into xerr and yerr
    string input = "error2D_float.txt";
    ReadData(input, xerr, yerr);

    // line equation now used to calculate the expected values and observed values
    double chi = 0;

    for (int i=0; i<N; i++) {
        double E = p * x[i] + q;
        double O = y[i];
        double sigma = yerr[i];
        chi += pow((O-E),2) / pow(sigma, 2);
    }

    // Degrees of freedom
    int params = 2;
    double dof = xerr.size() - params;
    double chi2_dof = chi / dof;
    
    string result = "Least squares fit: y = " + to_string(p) + " + " + to_string(q) + "x\n" 
    + "Chi^2 / NDOF = " + to_string(chi2_dof) + "x\n"
    + "Chi^2 = " + to_string(chi);

    Printer(result);

    ofstream outFile("Eqn_out.txt");
    if (outFile.is_open()) {
        outFile << result << endl;
        outFile.close();
    } else {
        cout << "Error! Could not open output file!" << endl;
    }

    return {p, q};
}

// x^y function
vector<double> XpY(vector<double>& x, vector<double>& y) {

    // manually x^y with rounded y values 
    function<double(double, int)> inpow = [&](double x, int n) -> double {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / inpow(x, -n);
        return x * inpow(x, n-1);
    };

    vector<double> result(x.size());

    // rounding each y term and using as the power to x
    transform(x.begin(), x.end(), y.begin(), result.begin(), [&inpow](double b, double e) {
        int rounded = round(e);
        return inpow(b, rounded);
    });
    return result;
}

// Overload for vector<double>
// Save a vector<double> to a file
void Lastfunc(const vector<double>& vec, const string& filename) {
    std::ofstream file(filename);
    if (!file) { 
        cerr << "Error opening file '" << filename << "'\n"; 
        return; 
    }
    for (const auto& val : vec) file << val << "\n";
}

// Save line equation y = slope * x + intercept
void Lastfunc(double p, double q, const string& filename) {
    std::ofstream file(filename);
    if (!file) { 
        cerr << "Error opening file '" << filename << "'\n"; 
        return; 
    }
    file << "y = " << p << "x + " << q << "\n";
}