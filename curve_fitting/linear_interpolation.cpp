#include <iostream>
using namespace std;

// Function to perform linear interpolation
double linearInterpolation(double x0, double y0, double x1, double y1, double x)
{
    // Formula: y = y0 + ( (y1 - y0) / (x1 - x0) ) * (x - x0)
    return y0 + ( (y1 - y0) / (x1 - x0) ) * (x - x0);
}

int main()
{
    double x0, y0, x1, y1, x;
    
    cout << "Enter first point (x0 y0): ";
    cin >> x0 >> y0;
    
    cout << "Enter second point (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter the value of x for interpolation: ";
    cin >> x;
    
    double interpolatedY = linearInterpolation(x0, y0, x1, y1, x);
    
    cout << "Interpolated value at x = " << x << " is y = " << interpolatedY << endl;
    
    return 0;
}
