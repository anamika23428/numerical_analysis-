#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> table_construction(vector<double> x, vector<double> y , int n){
	vector<vector<double>> table(n,vector<double>(n,-1));
	for(int i=0;i<n;i++){
		table[i][0]=y[i];
	}
	for(int col=1;col<n;col++){
		for(int row=col-1;row<n-1;row++){
			table[row+1][col]= table[row+1][col-1]-table[row][col-1];	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
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

int main(){
	int n=6;
	vector<double> x={-2,-1,0,1,2,3};
	vector<double> y={15,5,1,3,11,25};
	double k=0.5;
	cout<<"value of f at 0.5 is: ";
	cout<<forward_diff(x,y,n,k);
	cout<<endl;
	}
//value of f at 0.5 is: 1.25

