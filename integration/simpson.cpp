#include <iostream>
#include <cmath>
using namespace std;
#include <bits/stdc++.h>
double f(double x){
    return sin(x);
}
double simpson_1_3(double a,double b){
    return (((b-a)/6)*(f(a)+4*f((b+a)/2)+f(b)));
}
double simpson_3_8(double a,double b){
    double h=(b-a)/3;
    return ((3*h/8)*(f(a)+3*f(a+h)+3*f(a+2*h)+f(b)));
}
double composite_simpson_1_3(double a,double b,double h){
    double n=(b-a)/h;
    double ans=f(a)+f(b);
    double s1=0;
    double s2=0;
    for(int i=1;i<n;i++){
        double x = a + i * h;
        if (i % 2 == 0)
            s2 += f(x);
        else
            s1 += f(x);
    }
    ans=ans+4*s1+2*s2;
    return (h/3)*ans;
}

double composite_simpson_3_8(double a,double b,double h){
    double n=(b-a)/h;
    double ans=f(a)+f(b);
    double s1=0;
    double s2=0;
    for(int i=1;i<n;i++){
        double x = a + i * h;
        if (i % 3 == 0)
            s2 += f(x);
        else
            s1 += f(x);
    }
    ans=ans+3*s1+2*s2;
    return (3*h/8)*ans;

}


int main(){
    double a=0;
    double b=M_PI/2;
    double h=M_PI/8;
    double i=simpson_1_3(a,b);
    double i1=composite_simpson_1_3(a,b,h);
    double i2=simpson_3_8(a,b);
    double h2=M_PI/6;
    double i3=composite_simpson_3_8(a,b,h2);
    cout<<i<<endl;
    cout<<i1<<endl;
    cout<<i2<<endl;
    cout<<i3<<endl;
}