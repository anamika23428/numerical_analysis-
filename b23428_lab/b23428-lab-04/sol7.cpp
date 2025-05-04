#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define tol 1e-12

double fun(double x){
	return cos(x);
	}
	
//fixed point iteration
double fixed_point_iteration(double x0){
	double xi=fun(x0);
	int iterations=1;
	while(abs(xi-x0)>tol){
		iterations++;
		x0=xi;
		
		xi=fun(x0);
	}
	cout<<"Iterations: "<<iterations<<endl;
return xi;
}

double fun2(double x){
	return cos(x)-x;
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
		if(fun2(c)==0 ){
			cout<<"Iterations: "<<iterations<<endl; return c;}
		
	}
	cout<<"Iterations: "<<iterations<<endl;
return c;
}


//fixed_point_iteration: 
//Iterations: 70
//0.739085

//Secant: 
//Iterations: 7
//0.739085



int main(){
cout<<"fixed_point_iteration: "<<endl<<fixed_point_iteration(0.2)<<endl;
cout<<endl;
cout<<"Secant: "<<endl<<secant(0.2,0.9)<<endl;
}



