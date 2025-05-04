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
vector<double> x={10 , 20, 30, 40, 60, 70, 80, 90, 100};
vector<double> y = {12.34 , 18.78, 25.56 , 30.23, 34.56 , 33.78, 29.45 ,22.78 , 15.23};

//vector<double> x= {1,2,3,4};
//vector<double> y={0,0.3010, 0.4771 ,0.6021};

cout<<"missing value for speed 50mph is ";
double x50=newton(x,y,50);;
cout<<x50;
cout<<endl;
vector<double> x_={10 , 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<double> y_= {12.34 , 18.78, 25.56 , 30.23,x50, 34.56 , 33.78, 29.45 ,22.78 , 15.23};
cout<<"predicted value for 65mph is "<< newton(x_,y_,65);}


//missing value for speed 50mph is 33.042
//predicted value for 65mph is 34.5653


