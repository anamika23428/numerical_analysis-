#include <bits/stdc++.h>
using namespace std;

	
double newton(vector<double> x , vector<double> y,double k){
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
	
	
	
double newton_3deg(vector<double> x , vector<double> y,double k){
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
vector<double> x={100 ,200, 300,500, 600, 700, 800, 900,  1000};

vector<double> y = {1.12,1.45,1.89,2.78,3.12,3.45,3.89,4.56,5.12};



cout<<"missing value for distance 400 is ";
double m=newton(x,y,400);
cout<<m;
cout<<endl;

vector<double> x_={ 600, 700, 800, 900};
vector<double> y_= {3.12,3.45,3.89,4.56};


cout<<"predicted value for d=750 km for 3 degree polynomial is "<< newton(x_,y_,750);
}

//missing value for distance 400 is 2.36845
//predicted value for d=750 km for 3 degree polynomial is 3.64875
