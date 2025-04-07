#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<vector<double>> table(vector<double> a, vector<double> b,int n){
    vector<vector<double>> table(n,vector<double>(n,-1));
    for(int i=0;i<n;i++){
        table[i][0]=b[i];}
    for(int col=1;col<n;col++){
        for(int j=col-1;j<n-1;j++){
            table[j+1][col]= table[j+1][col-1]-table[j][col-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return table;
}

double forward_fun(vector<double> x, vector<double> y ,int n, double k){
     double s= (k-x[n-1])/(x[1]-x[0]);
   
    vector<vector<double>> diff_table = table(x,y,n);
    double ans=y[n-1];
    for(int i=1;i<n;i++){
        double term=1;
        for(int j=0;j<i;j++){
            term=term*((s+j)/(j+1));
        }
        ans=ans+term*diff_table[n-1][i];
        }
        return ans; 


}
int main(){
    int n;
    cin>>n;
    vector<double> x={10,20,30,40,50};
    vector<double> y={0.1736, 0.3420,0.5000,0.6428,0.7660};

    // for(int i=0;i<n;i++){
    //     double a,b;
    //     cin>>a>>b;
    //     x.push_back(a);
    //     y.push_back(b);
    //     }
        double k;
        cin>>k;
   cout<<forward_fun(x,y,n,k);
}