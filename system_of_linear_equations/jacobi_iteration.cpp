#include<bits/stdc++.h>
using namespace std;

#define e 1e-4

double fx(double y,double z){
	return (130 - 3*y + 2*z)/8;
	}
	
double fy(double x,double z){
	return (250 - 5*z -2*x)/10;
	}
	
double fz(double x,double y){
	return (190 + 3*x -6*y)/15;
	}
	
void jaccobi_iteration(double x0,double y0,double z0){
	double x=fx(y0,z0);
	double y=fy(x0,z0);
	double z=fz(x0,y0);
	int iter=1;
	while(abs(x-x0)>=e && abs(y-y0)>=e && abs(z-z0)>=e ){
		x0=x;
		y0=y;
		z0=z;
		x=fx(y0,z0);
		y=fy(x0,z0);
		z=fz(x0,y0);
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
	jaccobi_iteration(0,0,0);
	cout<<"converging as: "<<endl;
	cout<<"|dfx/x| + |dfy/x| + |dfz/x| = 0.4 <1"<<endl;
	cout<<"|dfx/y| + |dfy/y| + |dfz/y| = 0.775 <1"<<endl;
	cout<<"|dfx/z| + |dfy/z| + |dfz/z| = 0.75 <1"<<endl;
	}
//solution: 
//x: 10.7964
//y: 19.2846
//z: 7.11219
//iterations: 21
//converging as: 
//|dfx/x| + |dfy/x| + |dfz/x| = 0.4 <1
//|dfx/y| + |dfy/y| + |dfz/y| = 0.775 <1
//|dfx/z| + |dfy/z| + |dfz/z| = 0.75 <1

