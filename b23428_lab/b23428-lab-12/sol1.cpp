#include<bits/stdc++.h>
using namespace std;
double forward_difference(unordered_map<double,double> mpp, double k, double h){
	return (mpp[k+h]-mpp[k])/h;
	}

double central_difference(unordered_map<double,double> mpp, double k, double h){
	return (mpp[k+h]-mpp[k-h])/(2*h);
	}
	
double richard_extrapolation(unordered_map<double,double> mpp, double k, double h){
	return (2*forward_difference(mpp,k,h) - forward_difference(mpp,k,2*h));
}
int main(){
unordered_map<double ,double> mpp;
mpp[0.0]=12000;
mpp[0.2]=11980;
mpp[0.4]=11959;
mpp[0.6]=11936;
mpp[0.8]=11910;
mpp[1.0]=11885;
mpp[1.2]=11857;
mpp[1.4]=11828;
mpp[1.6]=11800;
mpp[1.8]=11769;
mpp[2.0]=11740;
mpp[2.2]=11710;
mpp[2.4]=11679;

double t=1.2;
double h1=0.4;
double ans1=forward_difference(mpp,t,h1);
cout<<"speed at t=1.2 using forward difference with h=0.4 : ";
cout<<ans1<<endl;
double h2=0.2;
double ans2=forward_difference(mpp,t,h2);
cout<<"speed at t=1.2 using forward difference with h=0.2 : ";
cout<<ans2<<endl;
double ans3=richard_extrapolation(mpp,t,0.2);
cout<<"speed at t=1.2 using richard_extrapolation : ";
cout<<ans3<<endl;
cout<<"absolute error of forward_difference with h=0.4 wrt extrapolation result is: "<<abs(ans3-ans1)<<endl;
cout<<"absolute error of forward_difference with h=0.2 wrt extrapolation result is: "<<abs(ans3-ans2)<<endl;

cout<<"sources of error: "<<endl;
cout<<"1. air resistance"<<endl;
cout<<"2. sensor noise"<<endl;
cout<<"3. error in recording time intervals"<<endl;

double time=1.4;
double speed=ans3;
double alt=12000+(speed*time);
cout<<"altitude at 1.4 is :"<<alt<<endl;
cout<<"absolute error in calculating altitude at t=1.4 is: "<< abs(alt - mpp[1.4])<<endl;

}
