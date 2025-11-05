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

    // uses printer func to print number of lines to terminal
    Printer(x,y);

    mag = magnitudes(x, y);


    // prints out all the magnitudes
    cout << endl <<"The magnitudes of x and y are: " << endl;
    for (auto i : mag) {
        cout << i << endl;
    }

    return 0;
}