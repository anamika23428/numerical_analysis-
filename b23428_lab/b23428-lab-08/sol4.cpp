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
int main(){

vector<double> x={2,3,4,5,6,7,9,10};
vector<double> y={1.23456789, 3.67891234, 6.78912345, 11.23456789,  17.78912345, 26.23456789,49.78912345,65.23456789};
double m=newton(x,y,8);
cout<< "flow rate at d=8cm is "<<m<<endl;
vector<double> x_={2,3,4,5,6,7,8,9,10};
vector<double> y_={1.23456789, 3.67891234, 6.78912345, 11.23456789,  17.78912345, 26.23456789,m,49.78912345,65.23456789};
cout<<"predicted value at 8.5 "<<newton(x_,y_,8.5);


}
//flow rate at d=8cm is 36.579
//predicted value at 8.5 42.7631
