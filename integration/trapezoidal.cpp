#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    return pow(x,3)+1;
}

double trapezoidal(double a, double b){
    return ((b-a)/2)*(f(a)+f(b));
}

double composite_trap(double a, double b, double h){
    double n=(b-a)/h;
    double ans=f(a)+f(b);
    for(int i=1;i<=n-1;i++){
        ans+=2*f(a+h*i);
    }
    return (h/2)*(ans);
}

int main(){
    double a=1;
    double b=2;
    double i=trapezoidal(a,b);
    double h=0.1;
    double i1=composite_trap(a,b,h);
    cout<<i<<endl;
    cout<<i1<<endl;
}

