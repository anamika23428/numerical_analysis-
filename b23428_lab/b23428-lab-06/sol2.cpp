#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define e 1e-6

double f(double x,double y){
	return pow(x,3)-3*x*pow(y,2) - pow(x,2) + pow(y,2) +4*x*y +3*x +y -2;
	}
	
double g(double x,double y){
	return  3*y*pow(x,2) - pow(y,3) -2*x*y -2*pow(x,2) +2*pow(y,2) +3*y -x;
	}
	
double f1(double x,double y){
	return 3*pow(x,2) -3*pow(y,2) - 2*x + 4*y +3 ;
	}
	
double g1(double x,double y){
	return 6*x*y -2*y - 4*x -1;
	}
	
double f2(double x,double y){
	return -6*x*y +2*y +4*x +1;
	}
	
double g2(double x,double y){
	return 3*pow(x,2) -3*pow(y,2) - 2*x + 4*y +3 ;
	}
	
double dx(double x, double y){
	return f(x,y)* g2(x,y) - g(x,y) * f2(x,y);}

double dy(double x, double y){
	return f1(x,y)* g(x,y) - g1(x,y) * f(x,y);}
	
double d(double x, double y){
	return f1(x,y)* g2(x,y) - g1(x,y) * f2(x,y);}

pair<double , double> newton(double x0, double y0){
	double x= x0 - dx(x0,y0)/d(x0,y0);
	double y= y0 - dy(x0,y0)/d(x0,y0);
	int iter =1;
	while(abs(x-x0)>=e && abs(y-y0)>=e){
		x0=x;
		y0=y;
		x= x0 - dx(x0,y0)/d(x0,y0);
		y= y0 - dy(x0,y0)/d(x0,y0);
	        
	        iter++;}
	cout<<"Iterartions: "<<iter<<endl;
	return {x,y};
}

int main(){
	
	
	cout<<"Newton-Raphson Method"<<endl;
	int power;
	cout<<"power of function: ";
	cin>>power;
	for(int i=0;i<power;i++){
		cout<<"solution "<<i+1 <<" :"<<endl;
		double x0,y0;
		cout<<"give the initial guess: ";
		cout<<endl;
		cout<<"x0: ";
		cin>>x0;
		cout<<"y0: ";
		cin>>y0;
        	pair<double,double> pp = newton(x0,y0);
		cout<<"x: "<< pp.first << " y: "<<pp.second <<endl;
	}
}


//Newton-Raphson Method
//power of function: 3
//solution 1 :
//give the initial guess: 
//x0: 1
//y0: 1
//Iterartions: 5
//x: 0.455912 y: 0.273728
//solution 2 :
//give the initial guess: 
//x0: -1
//y0: 1
//Iterartions: 5
//x: 0.455912 y: 0.273728
//solution 3 :
//give the initial guess: 
//x0: 0
//y0: -1
//Iterartions: 5
//x: -0.312295 y: -1.19524

