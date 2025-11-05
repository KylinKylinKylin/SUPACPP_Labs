#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Preliminary code: Vectors+magnitude

int main() {
    double x, y;
    x = 7.4;
    y = 3.4;
    double magnitude = sqrt(pow(x,2) + pow(y,2));

    cout << "The magnitude of " << x << " and " << y << " is: " << magnitude << endl;;
    return 0;
}