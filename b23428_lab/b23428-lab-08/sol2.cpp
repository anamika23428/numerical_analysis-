#include <bits/stdc++.h>
using namespace std;

	
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
vector<double> x={1,2,3,4,5,6,7,8,9,10};
vector<double> y = {150.56 ,152.78, 155.23,158.67, 162.78, 167.23,172.67,179.78,188.23,198.67};



cout<<"predicted value for day 1 is "<< langranges(x,y,11);
cout<<endl;
cout<<"absolute error: "<< abs(langranges(x,y,11)-210.56);
cout<<endl;
cout<<"predicted value for day 15 is "<< langranges(x,y,15);

}
//predicted value for day 1 is 219.7
//absolute error: 9.14
//predicted value for day 15 is 1172.76
