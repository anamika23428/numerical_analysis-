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
	
	vector<double> x={6,7,8,9,10,11,12,13,14,15};
	vector<double> y={15.0,15.9,17.1,18.2,20.5,21.8,23.0,24.1,25.2,25.9};
	int n=x.size();
	double k=8.5;
	double k1=13.5;
	double f1=forward_diff(x,y,n,k);
	double f2=forward_diff(x,y,n,k1);
	double b1=backward_diff(x,y,n,k);
	double b2=backward_diff(x,y,n,k1);
	
	cout<<"value of Temperature at 8:30 am using Newton Forward Interpolation is: ";
	cout<<f1<<setprecision(19)<<endl;
	cout<<"value of Temperature at 8:30 am using Newton Backward Interpolation is: ";
	cout<<b1<<setprecision(19);
	cout<<endl;
	
	cout<<"value of Temperature at 13:30 am using Newton Forward Interpolation is: ";
	cout<<f2<<setprecision(19)<<endl;
	cout<<"value of Temperature at 13:30 am using Newton Backward Interpolation is: ";
	cout<<b2<<setprecision(19);
	cout<<endl;
	
	cout<<"Absolute Difference of temperature at 8:30 using Newton Forward Interpolation  is: "<<abs(f1-17.7)<<endl;
	cout<<"Absolute Difference of temperature at 8:30 using Newton Backward Interpolation  is: "<<abs(b1-17.7)<<endl;
	cout<<"Absolute Difference of temperature at 13:30 using Newton forward Interpolation  is: "<<abs(f2-24.5)<<endl;
	cout<<"Absolute Difference of temperature at 13:30 using Newton Backward Interpolation  is: "<<abs(b2-24.5)<<endl;
	
	
	}

//value of Temperature at 8:30 am using Newton Forward Interpolation is: 17.3451
//value of Temperature at 8:30 am using Newton Backward Interpolation is: 17.34514465332031108
//value of Temperature at 13:30 am using Newton Forward Interpolation is: 24.41788024902342968
//value of Temperature at 13:30 am using Newton Backward Interpolation is: 24.41788024902343679
//Absolute Difference of temperature at 8:30 is: 0.3548553466796882105
//Absolute Difference of temperature at 13:30 is: 0.08211975097657031597




