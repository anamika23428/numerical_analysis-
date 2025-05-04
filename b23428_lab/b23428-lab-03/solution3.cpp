#include <iostream>
using namespace std;
#include <bits/stdc++.h>




double fun(double x ,int n){
return pow(x,2)-n;}


double bisection(double e, double a,double b ,int n){
double z=0;
int cnt=0;;
while((b-a)>e){
cnt++;
z=(a+b)/2;
double fz=fun(z,n);
double fa=fun(a,n);
double fb=fun(b,n);
if(fz == 0){return z;}
else if(fz*fa <0){b=z;}
else {a=z;}
}
cout<<"iterations in bisection: "<<cnt<<endl; 
return z;
}

double false_position(double e, double a,double b,int n){
double z=0;
int cnt=0;
while((b-a)>e){
cnt++;
double fa=fun(a,n);
double fb=fun(b,n);
z= (a*fb - b*fa)/(fb-fa);
double fz=fun(z,n);

if(fz == 0){return z;}
else if(fz*fa <0){b=z;}
else {a=z;}
}
cout<<"iterations in false_poosition: "<<cnt<<endl; 
return z;
}





int main(){
double e=pow(0.1,10);
int n;
cout<<"give me the value of n: "<<endl;
cin>>n;
cout<<"bisection: "<< fixed << setprecision(10)<<bisection(e,0,n,n)<<endl;
cout<<"false_position: "<<fixed << setprecision(10)<<bisection(e,0,n,n)<<endl;


return 0;}



//give me the value of n: 
//9
//bisection: iterations in bisection: 37
//3.0000000000
//false_position: iterations in bisection: 37
//3.0000000000

