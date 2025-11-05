#include <iostream>
#include <cmath>

using namespace std;

// Preliminary code: Take input values and calculates the magnitude

int main() {
    double x, y;

    cout << "Enter a value of x: ";
    cin >> x;

    cout << "Enter a value of y: ";
    cin >> y;

    double magnitude = sqrt(pow(x,2) + pow(y,2));

    cout << "The magnitude of " << x << " and " << y << " is: " << magnitude << endl;

    return 0;
}