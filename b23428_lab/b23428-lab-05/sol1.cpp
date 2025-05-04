#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//#define e1 1e-8
//#define e2 1e-8
double f(double x){
	return 2-5*pow(x,2)+exp(x);
	}
	
double g(double x){
	return exp(x)-10*x;
	}
double fun(double x){
	return sqrt((exp(x)+2)/5);}
double newton(double x0 ,double e1,double e2){
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

double fixed_point_iteration(double x0, double e1){
	double x=fun(x0);
	int iterations=1;
	while(abs(x-x0)>e1){
		iterations++;
		x0=x;
		x=fun(x0);
	}
	cout<<"Iterations: "<<iterations<<endl<<"x=";
return x;
}

int main(){
	double  x0;
	double e1,e2;
	cout<<"give the value of e1: ";
	cin>>e1;
	cout<<"give the value of e2: ";
	cin>>e2;
	cout<<"give the initial guess: ";
	cin>>x0;
	cout<<"Newton Raphson method"<<endl;
	cout<<"solution: "<<newton(x0,e1,e2)<<endl;
	cout<<"fixed point iteration"<<endl;
	cout<<"solution: "<<fixed_point_iteration(x0,e1)<<endl;
	
	}
	
//give the initial guess: 1
//Newton Raphson method
//solution: iteration taken: 4
//x=0.960529
//fixed point iteration
//solution: Iterations: 13
//x=0.960529


