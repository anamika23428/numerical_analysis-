#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> table_construction(vector<double> x, vector<double> y , int n){
	vector<vector<double>> table(n,vector<double>(n,0));
	for(int i=0;i<n;i++){
		table[i][0]=y[i];
	}
	for(int col=1;col<n;col++){
		for(int row=col-1;row<n-1;row++){
			table[row+1][col]= table[row+1][col-1]-table[row][col-1];	
		}
	}
	
	return table;
	}
	
double forward_diff(vector<double> x, vector<double> y , int n, double k){
	double s=(k-x[0])/(x[1]-x[0]);
	
	double ans= y[0];
	vector<vector<double>> diff_table= table_construction(x,y,n);
	for(int i=1;i<n;i++){
		double term=1;
		for(int j=0;j<i;j++){
		term= term*((s-j)/(j+1));
		}
		ans=ans+term*diff_table[i][i];
	}
	return ans;
	}
	
double backward_diff(vector<double> x, vector<double> y , int n, double k){
	double s=(k-x[n-1])/(x[1]-x[0]);
	
	double ans= y[n-1];
	vector<vector<double>> diff_table= table_construction(x,y,n);
	for(int i=1;i<n;i++){
		double term=1;
		for(int j=0;j<i;j++){
		term= term*((s+j)/(j+1));
		}
		ans=ans+term*diff_table[n-1][i];
	}
	return ans;
	}
	
	
int main(){
	int n=5;
	vector<double> x={0.1,0.2,0.3,0.4,0.5};
	vector<double> y={1.40, 1.56 ,1.76, 2.00, 2.28};
	vector<vector<double>> table= table_construction(x,y,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
		}
	cout<<endl;
	cout<<"Interpolation at 0.25 is: "<<forward_diff(x,y,n,0.25);
	cout<<endl;
	cout<<"Interpolation at 0.25 is: "<<backward_diff(x,y,n,0.35);
	
	
	}
//1.4 0 0 0 0 
//1.56 0.16 0 0 0 
//1.76 0.2 0.04 0 0 
//2 0.24 0.04 2.22045e-16 0 
//2.28 0.28 0.04 -2.22045e-16 -4.44089e-16 

//Interpolation at 0.25 is: 1.655
//Interpolation at 0.25 is: 1.875
