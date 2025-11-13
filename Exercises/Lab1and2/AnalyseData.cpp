#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "CustomFunctions.h"

using namespace std;

int main() {
    string inputfile = "input2D_float.txt";
    vector<double> x, y, mag, poww;
    double p, q;
    
    // uses readdata func to read the input data file
    ReadData(inputfile, x, y);

    // Initialize variables and asks user to input a value
    int N;
    cout << "Enter the number of lines from the data file you want to be printed to the terminal: ";
    cin >> N;

    cout << "The number you entered was: " << N << endl;

    // uses printer func to print number of lines to terminal
    Printer(x,y,N);

    // Uses the magnitudes function to calculate all the magnitudes
    mag = magnitudes(x, y);

    // Uses the least squares function to find the line of best fit for the data points
    // Outputs to the terminal and to a text file "Eqn_out.txt"
    tie(p, q) = BestFit(x,y,N);

    // running x^y 
    poww = XpY(x, y);

    cout << "What would you like to save? (mag, x^y, line, all, none): ";
    string input;
    cin >> input;

    if (input == "magnitude") {
        Lastfunc(mag, "magnitude.txt");
    } 
    else if (input == "x^y") {
        Lastfunc(poww, "x^y.txt");
    }
    else if (input == "line") {
        Lastfunc(p, q, "Straight_line.txt");
    }
    else if (input == "all") {
        Lastfunc(mag, "magnitude.txt");
        Lastfunc(poww, "x^y.txt");
        Lastfunc(p, q, "Straight_line.txt");
    }
    else if (input == "none") {
        return 0;
    }
    else {
        cout << "Invalid input please choose from (Magnitude, x^y, Straight line, all, none)" << endl;
    }
    return 0;
}