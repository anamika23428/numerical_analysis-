#include<bits/stdc++.h>
using namespace std;

struct SplineSegement{
    double a, b, c, d, x;
};

vector<SplineSegement> cubicspline(vector<double> x, vector<double> y){
    int n = x.size() - 1;
    vector<double> h(n);
    for(int i = 0; i < n; i++){
        h[i] = x[i + 1] - x[i];
    }
    
    vector<double> alpha(n);
    for(int i = 1; i < n; i++){
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    vector<double> l(n + 1), mu(n + 1), z(n + 1);
    l[0] = 1; mu[0] = z[0] = 0;

    for(int i = 1; i < n; i++){
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n] = 1;
    z[n] = 0;

    vector<double> c(n + 1), b(n), d(n);
    for(int j = n - 1; j >= 0; j--){
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
    }

    vector<SplineSegement> spline(n);  
    for(int i = 0; i < n; i++){
        spline[i].a = y[i];
        spline[i].b = b[i];
        spline[i].c = c[i];
        spline[i].d = d[i];
        spline[i].x = x[i];
    }
    
    return spline;
}

double evaluatesplines(vector<SplineSegement>& spline, double x_val){
    int n = spline.size();
    int i = n - 1;
    for(int j = 0; j < n - 1; j++){  
        if(x_val < spline[j + 1].x){
            i = j;
            break;
        }
    }

    double dx = x_val - spline[i].x;
    return spline[i].a + spline[i].b * dx + spline[i].c * dx * dx + spline[i].d * dx * dx * dx;
}

int main(){
    vector<double> x = {0, 1, 2, 3, 4};
    vector<double> y = {0, 1.5, 1.8, 2.5, 3.2};

    auto splines = cubicspline(x, y);
    double k = 1.5;
    double res = evaluatesplines(splines, k);
    cout << res << endl;
    k=2.7;
    res=evaluatesplines(splines, k);
     cout << res << endl;
    
}

//1.70625
//2.25325


