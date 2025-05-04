#include <iostream>
#include <cmath>
using namespace std;

// Define the integrand function f(x)
double f(double x) {
    // Example: f(x) = x^2
    return x * x;
}

double simpson(int N,double a, )
// Composite Simpson's 1/3 Rule function
double simpsonComposite(int N, double a, double b) {
    if (N % 2 != 0) {
        cerr << "Error: N must be even for Simpson's 1/3 Rule." << endl;
        return NAN;
    }

    double h = (b - a) / (2.0 * N);
    double Sum = 0.0;
    double Sum1 = f(a + h);

    for (int i = 1; i <= N - 1; i++) {
        double x_even = a + h * (2 * i);
        double x_odd = a + h * (2 * i + 1);
        Sum += f(x_even);
        Sum1 += f(x_odd);
    }

    Sum = 2 * Sum + 4 * Sum1 + f(a) + f(b);
    return (h * Sum) / 3.0;
}

int main() {
    int N;
    double a, b;

    cout << "Enter number of subintervals (even N): ";
    cin >> N;
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;

    double result = simpsonComposite(N, a, b);
    if (!isnan(result)) {
        cout << "Approximate integral value: " << result << endl;
    }
}
