#include <bits/stdc++.h>
using namespace std;


vector<double> divide_diff(vector<double> x, vector<double> y){
	int n=x.size();
	vector<vector<double>> table (n,vector<double>(n,0));
	for(int i=0;i<n;i++){
		table[i][0]=y[i];}
		
	for(int c=1;c<n;c++){
		for(int r=0;r<n-c;r++){
		table[r][c] = (table[r+1][c-1]-table[r][c-1])/(x[r+c]-x[r]);
	}
	}
	return table[0];
}
	
double newton(vector<double> x , vector<double> y,double k){
int n=x.size();
	vector<double> coef= divide_diff(x,y);
	double res=coef[0];
	for(int i=1;i<n;i++){
		double term=coef[i];
		for(int j=0;j<=i-1;j++){
			term*=(k-x[j]);
		}
		res=res+term;}
	return res;
	}
	
double langranges(vector<double> x , vector<double> y,double k){
	int n=x.size();
	double res=0;
	for(int i=0;i<n;i++){
	double term= y[i];
		for(int j=0;j<n;j++){
			if(j!=i){
				term*=(k-x[j])/(x[i]-x[j]);
			}
		}
		res=res+term;
	}
	return res;}	
	
int main(){
vector<double> x={0,2,4,6,8,10,12,14,16,18};
vector<double> y = {400.0,401.3,402.7,403.6,405.0,407.8,409.0,410.2,412.0,413.5};

double k1=9;

cout<<"altitude at "<<k1<<" :"<<endl;
double l1=langranges(x,y,k1);
double n1=newton(x,y,k1);
cout<<"using Langranges's Interpolation is: "<<l1<<setprecision(19)<<endl;
cout<<"using Newton divided difference is: "<<n1<<setprecision(19)<<endl;

cout<<"Actual value is 15.4 km/l"<<endl;
cout<<"Absolute difference when interpolated using langranges is : "<<abs(l1-406)<<endl;
cout<<"Absolute difference when interpolated using Newton Divided Difference is : "<<abs(n1-406)<<endl;



vector<double> x_new={0,2,4,6,8,12,14,16,18};
vector<double> y_new = {400.0,401.3,402.7,403.6,405.0,409.0,410.2,412.0,413.5};

double k3=9;
cout<<"After removing 10"<<endl;
cout<<"Altitude at "<<k3<<" :"<<endl;
double l3=langranges(x_new,y_new,k3);
double n3=newton(x_new,y_new,k3);
cout<<"using Langranges's Interpolation is: "<<l3<<setprecision(19)<<endl;
cout<<"using Newton divided difference is: "<<n3<<setprecision(19)<<endl;

cout<<"Actual value is 15.4 km/l"<<endl;
cout<<"Absolute difference when interpolated using langranges is : "<<abs(l3-406)<<endl;
cout<<"Absolute difference when interpolated using Newton Divided Difference is : "<<abs(n3-406)<<endl;
}



//406

