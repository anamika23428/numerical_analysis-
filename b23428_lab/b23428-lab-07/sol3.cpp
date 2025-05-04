#include<bits/stdc++.h>
using namespace std;



double fx(double y,double z){
	return (0.07 - 0.03*z - 0.04*y)/0.08;
	}
	
double fy(double x,double z){
	return (0.06 - 0.03*x - 0.02*z)/(0.09);
	}
	
double fz(double x,double y){
	return (0.08 - 0.05*x - 0.02*y)/(0.07);
	}
	
void gauss_seidel(double x0,double y0,double z0){
	double x=fx(y0,z0);
	double y=fy(x,z0);
	double z=fz(x,y);
	int iter=1;
	while(iter<10 ){
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
//x: 0.414794
//y: 0.363343
//z: 0.742764
//iterations: 10

