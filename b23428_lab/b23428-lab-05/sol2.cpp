#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define e1 1e-8
#define e2 1e-8
#define tol 1e-12
double f(double x){
	return log(x+2)-cos(x);
	}
	
double g(double x){
	return 1/(x+2)+sin(x);
	}

double fun(double x){
	return acos(log(x+2));}
	
double newton(double x0){
	double x= x0 - f(x0)/g(x0);
	int iter=1;
	while( abs(x-x0)>e1 || abs(f(x0)-f(x))>e2 ){
		x0=x;
		if(g(x0)==0){cout<<" g'(X) becomes 0"; break;}
		x=x0-f(x0)/g(x0);
		iter++;
		
	}
	cout<<"iteration taken: "<<iter<<endl<<"x=";
	return x;
	}
	
double fixed_point_iteration(double x0){
	double x=fun(x0);
	int iterations=1;
	while(abs(x-x0)>tol){
		iterations++;
		x0=x;
		x=fun(x0);
	}
	cout<<"Iterations: "<<iterations<<endl<<"x=";
return x;
}

int main(){
	double x0;
	cout<<"give the initial guess: ";
	cin>>x0;
	cout<<"Newton Raphson method"<<endl;
	cout<<"solution: "<<newton(x0)<<endl;
	cout<<"fixed point iteration"<<endl;
	cout<<"solution: "<<fixed_point_iteration(x0)<<endl;
	
	}
	
//give the initial guess: 0.5
//Newton Raphson method
//solution: iteration taken: 4
//x=0.455159
//fixed point iteration
//solution: Iterations: 332
//x=0.455159


