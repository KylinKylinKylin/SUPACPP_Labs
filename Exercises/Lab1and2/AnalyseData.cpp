#include <iostream>
#include <vector>
#include <string>
#include "CustomFunctions.h"

using namespace std;

int main() {
    string inputfile = "input2D_float.txt";
    vector<double> x, y, mag;
    
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


    // prints out all the magnitudes
    cout << endl <<"The first 5 magnitudes of x and y are: " << endl;
    for (int i=0; i<5; i++) {
        cout << mag[i] << endl;
    }

    // Uses the least squares function to find the line of best fit for the data points
    // Outputs to the terminal and to a text file "Eqn_out.txt"
    BestFit(x,y,N);

    // Using the chi_squared function to determine the goodness of fit
    Chi_squared(N, x, y);

    return 0;
}