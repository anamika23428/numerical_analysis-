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
	int n=3;
	vector<double> x={0,5,10};
	vector<double> y1={1000,1010,1020};
	vector<double> y2={1200,1210,1220};
	vector<double> y3={900,910,920};
	
	double k=7;
	double dis1=forward_diff(x,y1,n,k);
	double dis2=forward_diff(x,y2,n,k);
	double dis3=forward_diff(x,y3,n,k);
	cout<<"distance by satellite 1 is: "<<dis1<<endl;
	cout<<"distance by satellite 2 is: "<<dis2<<endl;
	cout<<"distance by satellite 3 is: "<<dis3<<endl;
	cout<<endl;
	}

//distance by satellite 1 is: 1014
//distance by satellite 2 is: 1214
//distance by satellite 3 is: 914


