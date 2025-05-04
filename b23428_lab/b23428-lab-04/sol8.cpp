#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define tol 1e-4
double fun(double x){
	return sqrt(x+1)-x*x+x;
	}
	
//fixed point iteration
double fixed_point_iteration(double x0){
	double xi=fun(x0);
	int iterations=1;
	while(abs(xi-x0)>tol && iterations<10){
		iterations++;
		x0=xi;
		cout<<xi<<endl;
		xi=fun(x0);
	}
	cout<<"Iterations: "<<iterations<<endl;
return (xi);
}

double fun2(double x){
	return sqrt(x+1)-x*x;
	}
//secant
double secant(double a,double b){
	double c=0;
	int iterations=1;
	while(abs(a-b)>tol){
		iterations++;
		double  fa=fun2(a);
		double  fb=fun2(b);
		
		if(fa-fb == 0){cout<<"denominator becomes zero"<<endl;cout<<"Iterations: "<<iterations<<endl;return 0;}
		if(fa==0){
			cout<<"Iterations: "<<iterations<<endl;
			return a;}
		else if(fb==0)
			{cout<<"Iterations: "<<iterations<<endl; 
			return b;}
		c=(a*fb-b*fa)/(fb-fa);
		a=b;
		b=c;
		if(fun2(c)==0  ){
			cout<<"Iterations: "<<iterations<<endl; return c;}
		
	}
	cout<<"Iterations: "<<iterations<<endl;
return c;
}




int main(){
cout<<endl;
cout<<"Secant: "<<endl<<secant(0.1,0.9)<<endl;
cout<<"fixed_point_iteration: "<<endl<<fixed_point_iteration(0.1)<<endl;

}

//Secant: 
//Iterations: 7
//1.22074
//fixed_point_iteration: 
//1.13881
//1.30439
//1.12098
//1.32074
//1.09978
//1.33933
//1.07502
//1.35985
//1.04684
//Iterations: 10
//1.38164


