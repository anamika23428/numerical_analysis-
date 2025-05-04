#include <iostream>
#include <vector>
using namespace std;

struct SplineSegment {
    double a, b, c, d, x;
};

vector<SplineSegment> cubicSpline(const vector<double>& x, const vector<double>& y) {
    int n = x.size() - 1;
    vector<double> h(n), alpha(n);
    
    // Calculate step sizes
    for (int i = 0; i < n; i++)
        h[i] = x[i + 1] - x[i];

    // Calculate alpha terms
    for (int i = 1; i < n; i++)
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);

    // Solve the system for the spline coefficients
    vector<double> l(n + 1), mu(n + 1), z(n + 1);
    l[0] = 1; mu[0] = z[0] = 0;

    for (int i = 1; i < n; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n] = 1; z[n] = 0;

    vector<double> c(n + 1), b(n), d(n);
    for (int j = n - 1; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
    }

    vector<SplineSegment> splines(n);
    for (int i = 0; i < n; i++) {
        splines[i].a = y[i];
        splines[i].b = b[i];
        splines[i].c = c[i];
        splines[i].d = d[i];
        splines[i].x = x[i];
    }

    return splines;
}

double evaluateSpline(const vector<SplineSegment>& splines, double x_val) {
    int n = splines.size();
    int i = n - 1;
    for (int j = 0; j < n; j++) {
        if (x_val < splines[j + 1].x) {
            i = j;
            break;
        }
    }

    double dx = x_val - splines[i].x;
    return splines[i].a + splines[i].b * dx + splines[i].c * dx * dx + splines[i].d * dx * dx * dx;
}

int main() {
    vector<double> x = {4, 9, 16};
    vector<double> y = {2, 3, 4};

    // Generate cubic splines
    auto splines = cubicSpline(x, y);

    // Evaluate spline at a specific x-value
    double x_val = 7;
    double result = evaluateSpline(splines, x_val);

    cout << "Spline evaluated at x = " << x_val << ": " << result << endl;

    return 0;
}
