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
vector<double> x={10 , 20, 30, 40, 60, 70, 80, 90, 100};
vector<double> y = {10.5,12.5,13.7,14.8,16.0,17.2,16.8,15.5,14.2,13.0};

double k=45;

cout<<"Fuel efficiency at "<<k<<" :"<<endl;
double l1=langranges(x,y,k);
double n1=newton(x,y,k);
cout<<"using Langranges's Interpolation is: "<<l1<<setprecision(19)<<endl;
cout<<"using Newton divided difference is: "<<n1<<setprecision(19)<<endl;

cout<<"Actual value is 15.4 km/l"<<endl;
cout<<"Absolute difference when interpolated using langranges is : "<<abs(l1-15.4)<<endl;
cout<<"Absolute difference when interpolated using Newton Divided Difference is : "<<abs(n1-15.4)<<endl;
// both interpolation gives same values so accuracy is same for both

double k2=110;
cout<<"Fuel efficiency at "<<k2<<" :"<<endl;
double l2=langranges(x,y,k2);
double n2=newton(x,y,k2);
cout<<"using Langranges's Interpolation is: "<<l2<<setprecision(19)<<endl;
cout<<"using Newton divided difference is: "<<n2<<setprecision(19)<<endl;
vector<double> x_new={10 , 20, 30, 40, 60, 70, 80, 90, 100};
vector<double> y_new = {10.5,12.5,13.7,14.8,16.0,25.0,16.8,15.5,14.2,13.0};

double k3=45;

cout<<"Fuel efficiency at "<<k3<<" :"<<endl;
double l3=langranges(x_new,y_new,k3);
double n3=newton(x_new,y_new,k3);
cout<<"using Langranges's Interpolation is: "<<l3<<setprecision(19)<<endl;
cout<<"using Newton divided difference is: "<<n3<<setprecision(19)<<endl;

}





