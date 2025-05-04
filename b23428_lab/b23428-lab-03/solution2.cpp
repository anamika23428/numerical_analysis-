#include <iostream>
using namespace std;
#include <bits/stdc++.h>




double fun(double x){
return 100*pow(1/M_E,x) + 10*(pow(x,2)) -50;}


double bisection(double e, double a,double b){
double z=0;
int cnt=0;;
while((b-a)>e){
cnt++;
z=(a+b)/2;
double fz=fun(z);
double fa=fun(a);
double fb=fun(b);
if(fz == 0){return z;}
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

if(fz == 0){return z;}
else if(fz*fa <0){b=z;}
else {a=z;}
}
cout<<"iterations in false_poosition: "<<cnt<<endl; 
return z;
}





int main(){
double e=pow(0.1,10);
cout<<"interval : [0,1]"<<endl;
cout<<"bisection: "<< fixed << setprecision(10)<<bisection(e,0,1)<<endl;
cout<<"false_position: "<<fixed << setprecision(10)<<bisection(e,0,1)<<endl;


return 0;}


//interval : [0,1]
//bisection: iterations in bisection: 34
//0.8487003937
//false_position: iterations in bisection: 34
//0.8487003937

