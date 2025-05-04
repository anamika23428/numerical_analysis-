#include<bits/stdc++.h>
using namespace std;

#define e 1e-5

double fx(double y,double z){
	return (90 + 0.4*y -0.3*z)/1.2;
	}
	
double fy(double x,double z){
	return (120 +0.5*x + 0.7*z)/1.8;
	}
	
double fz(double x,double y){
	return (150 -0.2*x + 0.6*y)/5;
	}
	
void SOR(double x0i,double y0i,double z0i , double x0r,double y0r,double z0r , double r){
	double xi=fx(y0i,z0i);
	double yi=fy(xi,z0i);
	double zi=fz(xi,yi);
	
	double xr=r*(xi) + (1-r)*x0r;
	double yr=r*(yi) + (1-r)*y0r;
	double zr=r*(zi) + (1-r)*z0r;
	
	int iter=1;
	while(abs(xr-x0r)>=e && abs(yr-y0r)>=e && abs(zr-z0r)>=e ){
		x0i=xi;
		y0i=yi;
		z0i=zi;
		
		xi=fx(y0i,z0i);
		yi=fy(xi,z0i);
		zi=fz(xi,yi);
		
		x0r= xr;
		y0r=yr;
		z0r=zr;
		
		xr=r*(xi) + (1-r)*x0r;
	 	yr=r*(yi) + (1-r)*y0r;
		zr=r*(zi) + (1-r)*z0r;
		iter++;
	} 
	cout<<"solution using sor: "<<endl;
	cout<<"x: "<<xr<<endl;
	cout<<"y: "<<yr<<endl;
	cout<<"z: "<<zr<<endl;
	cout<<"iterations: "<<iter<<endl;
	return ;
	}


int main(){
        cout<<"with r=1.1 i get my answer with minimum iteration"<<endl;
	SOR(0,0,0,0,0,0,1.1);
	}
	
	
	
//with r=1.1 i get my answer with minimum iteration
//solution using sor: 
//x: 101.95
//y: 110.21
//z: 39.1472
//iterations: 8
	
	
	
	
