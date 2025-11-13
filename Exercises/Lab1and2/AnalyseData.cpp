#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "CustomFunctions.h"

using namespace std;

int main() {
    string inputfile = "input2D_float.txt";
    vector<double> x, y, mag, xpy;
    
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
    BestFit(x,y,N);

    return 0;
}