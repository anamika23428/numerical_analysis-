#include<bits/stdc++.h>
using namespace std;

#define e 1e-5

double fx(double y,double z){
	return (150 +y)/3;
	}
	
double fy(double x,double z){
	return (200 +2*x + z)/4;
	}
	
double fz(double x,double y){
	return (250 + 3*y)/5;
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
		
		x0r=xr;
		y0r=yr;
		z0r=zr;
		
		xr=r*(xi) + (1-r)*x0r;
	 	yr=r*(yi) + (1-r)*y0r;
		zr=r*(zi) + (1-r)*z0r;
		iter++;
	} 
	cout<<"solution using sor: "<<endl;
	cout<<"T1: "<<xr<<endl;
	cout<<"T2: "<<yr<<endl;
	cout<<"T3: "<<zr<<endl;
	cout<<"iterations: "<<iter<<endl;
	return ;
	}
	
	
void gauss_seidel(double x0,double y0,double z0){
	double x=fx(y0,z0);
	double y=fy(x,z0);
	double z=fz(x,y);
	int iter=1;
	while(abs(x-x0)>=e && abs(y-y0)>=e && abs(z-z0)>=e ){
		x0=x;
		y0=y;
		z0=z;
		x=fx(y0,z0);
		y=fy(x,z0);
		z=fz(x,y);
		iter++;
	} 
	cout<<"solution using gauss seidel : "<<endl;
	cout<<"T1: "<<x<<endl;
	cout<<"T2: "<<y<<endl;
	cout<<"T3: "<<z<<endl;
	cout<<"iterations: "<<iter<<endl;
	return ;
	}
int main(){
	SOR(0,0,0,0,0,0,1.3);
	gauss_seidel(0,0,0);
	
	}
	
//solution using sor: 
//T1: 92.6828
//T2: 128.049
//T3: 126.829
//iterations: 12
//solution using gauss seidel : 
//T1: 92.6829
//T2: 128.049
//T3: 126.829
//iterations: 15

