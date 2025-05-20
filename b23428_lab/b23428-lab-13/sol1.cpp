#include<bits/stdc++.h>
using namespace std;
double n=12;


double f(double x){return pow(x,3)+1;}

double trapezoidal(double a, double b){
return ((b-a)/2)*(f(a)+f(b));
}

double simpson_1_3(double a, double b){
return ((b-a)/6)*(f(a)+f(b)+4*f((a+b)/2));
}

double composite_trap(double a,double b){
double h=(b-a)/n;
double ans=f(a)+f(b);
for(int i=1;i<=n-1;i++){
	ans=ans+2*(f(a+h*i));
}
return (ans)*(h/2);
}


double comp_simpson_1_3(double a, double b){
	double h=(b-a)/n;
	double ans=f(a)+f(b);

	double s1=0;
	double s2=0;
	
	for(int i=1;i<n;i++){
	double x=a+i*h;
	if(i%2==0){ s2=s2+(f(x));}
	else{s1=s1+f(x);}
}
return h/3*(ans + 4*s1 + 2*s2);
}

double simpson_3_8(double a,double b){
	double h=(b-a)/n;
	double ans=f(a)+f(b);
	double s1=0;
	double s2=0;
	
	for(int i=1;i<n;i++){
	double x=a+i*h;
	if(i%3==0){ s2=s2+(f(x));}
	else{s1=s1+f(x);}
}
return (3*h)/8*(ans + 3*s1 + 2*s2);}

int main(){


double a=1;
double b=2;
cout<<"Integration with trapezoidal rule is: "<<trapezoidal(a,b)<<endl;
cout<<"Integration with composite trapezoidal rule is: "<<composite_trap(a,b)<<endl;
cout<<"Integration with simpon rule is: "<<simpson_1_3(a,b)<<endl;
cout<<"Integration with composite simpon rule is: "<<comp_simpson_1_3(a,b)<<endl;
cout<<"Integration with composite simpon 3/8 rule is: "<< simpson_3_8(a,b)<<endl;
}

