#include<bits/stdc++.h>
using namespace std;

#define e 1e-5

double fx(double y,double z){
	return (10 - 3*z + 4*y)/12;
	}
	
double fy(double x,double z){
	return (25 + 3*x +6*z)/(14);
	}
	
double fz(double x,double y){
	return (40 - 5*x +2*y)/17;
	}
	
void gauss_seidel(double x0,double y0,double z0){
	double x=fx(y0,z0);
	double y=fy(x,z0);
	double z=fz(x,y);
	int iter=1;
	while(abs(x-x0)>=e && abs(y-y0)>=e && abs(z-z0)>=e){
		x0=x;
		y0=y;
		z0=z;
		x=fx(y0,z0);
		y=fy(x,z0);
		z=fz(x,y);
		iter++;
	} 
	cout<<"solution: "<<endl;
	cout<<"x: "<<x<<endl;
	cout<<"y: "<<y<<endl;
	cout<<"z: "<<z<<endl;
	cout<<"iterations: "<<iter<<endl;
	return ;
	}
	
int main(){
	gauss_seidel(0,0,0);
	}
//solution: 
//x: 1.26845
//y: 3.06034
//z: 2.33991
//iterations: 8
