#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define e1 1e-6

double f(double x, double y){
	return y/exp(x);
	}
	
double g(double x , double y){
	return sqrt(cos(x));
	}

pair<double,double> fixed_point_iteration(double x0, double y0){
	double x=f(x0,y0);
	double y=g(x0,y0);
	int iterations=1;
	while(abs(x-x0)>e1 && abs(y-y0)>e1){
		iterations++;
		x0=x;
		y0=y;
		y=g(x0,y0);
		x=f(x0 ,y0);
	}
	cout<<"Iterations: "<<iterations<<endl<<"x=";
return {x,y};
}

int main(){
	double x0,y0;
	cout<<"give the initial guess: ";
	cout<<endl;
	cout<<"x0: ";
	cin>>x0;
	cout<<"y0: ";
	cin>>y0;
	cout<<"fixed point iteration"<<endl;
        pair<double,double> pp = fixed_point_iteration(x0,y0);
	cout<<"solution: x: "<< pp.first << " y: "<<pp.second <<endl;
	
	}
	
	
	
//give the initial guess: 
//x0: 0.5
//y0: 0.7
//fixed point iteration
//Iterations: 16
//x=solution: x: 0.539823 y: 0.926175


