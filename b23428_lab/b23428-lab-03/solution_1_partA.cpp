#include <iostream>
using namespace std;
#include <bits/stdc++.h>


double fun(double x)
	{
		return 2*pow(x,6) - 5*pow(x,4) +2;
	}



double bisection(double e, double a,double b){
double z=0;
int cnt=0;;
while((b-a)>e){
cnt++;
z=(a+b)/2;
double fz=fun(z);
double fa=fun(a);
double fb=fun(b);
if(fz == 0){cout<<"iterations in bisection: "<<cnt<<endl;  return z;}
else if(fz*fa <0){b=z;}
else {a=z;}
}
cout<<"iterations in bisection: "<<cnt<<endl; 
return z;
}

double false_position(double e, double a,double b){
double z=0;
int cnt=0;
while((b-a)>e){
cnt++;
double fa=fun(a);
double fb=fun(b);
z= (a*fb - b*fa)/(fb-fa);
double fz=fun(z);

if(fz == 0){cout<<"iterations in bisection: "<<cnt<<endl;  return z;}
else if(fz*fa <0){b=z;}
else {a=z;}
}
cout<<"iterations in false_poosition: "<<cnt<<endl; 
return z;
}





int main(){
double e=pow(0.1,8);


int a;
int b;
cout<<"initial value of interval: "<<endl;
cin>>a;
cout<<"ending value of interval: "<<endl;
cin>>b;
while(a<b){
if(fun(a)*fun(b) <0){break;}
a++;
}
if(a==b){cout<<"NO solution exist in this interval"; return 0;}
cout<<"interval : ["<<a<<","<<b<<"]"<<endl;
cout<<"bisection: "<< fixed << setprecision(8)<<bisection(e,a,b)<<endl;
cout<<"false_position: "<<fixed << setprecision(8)<<bisection(e,a,b)<<endl;


return 0;}

//initial value of interval: 
//-5
//ending value of interval: 
///5
//interval : [-1,5]
//bisection: iterations in bisection: 30
//-0.87038441
//false_position: iterations in bisection: 30
//-0.87038441



