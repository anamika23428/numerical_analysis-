#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

vector<double> gaussjordan(vector<vector<double>> input,int n){
    for(int i=0;i<n;i++){
        double p=input[i][i];
        for (int j = 0; j < n + 1; j++) {
            input[i][j] /= p;
        }
        for(int j=0;j<n;j++){
            if(i==j){continue;}
            double factor=input[j][i];
            for(int k=0;k<n+1;k++){
                    input[j][k]=input[j][k]-input[i][k]*factor;
            }
        }}
        vector<double> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=input[i][n];
        }
        return ans;
    
}

int main(){
    int n = 3;
    vector<vector<double>> vec = {
        {3, 2, -1, 1},
        {2, -2, 4, -2},
        {-1, 0.5, -1, 0}
    };
    vector<double> ans=gaussjordan(vec,n);
    for(double i:ans){cout<<i<<" ";}
}