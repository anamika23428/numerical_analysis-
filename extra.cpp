#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

// vector<double> fun(vector<vector<double>> arr,int n){
// for(int i=0;i<n-1;i++){
//     for(int j=i+1;j<n;j++){
//         double f= arr[j][i]/arr[i][i];
//         for(int k=0;k<=n;k++){
//             arr[j][k]=arr[j][k]-f*arr[i][k];
//         }
//     }
// }
// vector<double> vec(n,0);
// for(int i=n-1;i>=0;i--){
//     vec[i]=arr[i][n];
//     for(int j=i+1;j<n;j++){
//         vec[i]=vec[i]-arr[i][j]*vec[j];
//     }
//     vec[i]=vec[i]/arr[i][i];
// }
// return vec;}

// vector<double> fun2(vector<vector<double>> arr, int n){
//     for(int i=0;i<n;i++){
//         double f1=arr[i][i];
//         for(int k=0;k<=n;k++){
//             arr[i][k]=arr[i][k]/f1;
//         }

//         for(int j=0;j<n;j++){
//             if(j!=i){
//             double f=arr[j][i];
//             for(int k=0;k<=n;k++){
//                 arr[j][k]=arr[j][k]-f*arr[i][k];
//             }
//         }
//         }
//     }

//     vector<double> vec(n,0);
//     for(int i=n-1;i>=0;i--){
//        vec[i]=arr[i][n];
//     }
//     return vec;
// }



// int main(){
//     vector<vector<double>> a = {
//         {3.0, 2.0, -1.0 , 1.0},
//         {2.0, -2.0, 4.0 , -2.0},
//         {-1.0, 0.5, -1.0 ,0.0}
//     };
//     int n=3;
//     vector<double> ans=fun2(a,n);
//     for(double i:ans){cout<<i<<" ";}
// }


//langranges

double langranges(vector<double> x, vector<double> y , double k){
    double ans=0;
    int n=x.size();
    for(int i=0;i<n;i++){
        double t=y[i];
        for(int j=0;j<n;j++){
            if(j!=i){
                t=t*(k-x[j])/(x[i]-x[j]);
            }
        }
        ans=ans+t;
    }
    return ans;
}


vector<double>  divide_diff(vector<double> x, vector<double> y){
    int n=x.size();
    vector<vector<double>> table(n,vector<double> (n,0));
    for(int i=0;i<n;i++){
        table[i][0]=y[i];
    }

    for(int c=1;c<n;c++){
        for(int r=0;r<n-c;r++){
            table[r][c]=(table[r+1][c-1]-table[r][c-1])/(x[r+c]-x[r]);
        }
    }
    return table[0];
}

double newton(vector<double> x, vector<double> y,double k){
    vector<double> table=divide_diff(x,y);
    int n=x.size();
    double ans=y[0];
    for(int i=1;i<n;i++){
        double term=table[i];
        for(int j=0;j<i;j++ ){
            term*=(k-x[j]);
        }
        ans=ans+term;
    }
    return ans;
}



vector<vector<double>> diff_forward(vector<double> x, vector<double> y){
    int n=x.size();
    vector<vector<double>> table(n,vector<double> (n,0));
    for(int i=0;i<n;i++){
        table[i][0]=y[i];
    }

    for(int c=1;c<n;c++){
        for(int r=0;r<n-c;r++){
            table[r][c]=(table[r+1][c-1]-table[r][c-1]);
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
    return table;
}

double fun(vector<double> x, vector<double> y,double k){
    double ans=y[0];
    vector<vector<double>> table=diff_forward(x,y);
    int n=x.size();
    double s=(k-x[0])/(x[1]-x[0]);
    for(int i=1;i<n;i++){
        double term=1;
        for(int j=0;j<i;j++){
            term=term*(s-j)/(j+1);
        }
        ans+=term*table[0][i];
    }
    return ans;
}

	
int main(){
	int n=6;
	vector<double> x={-2,-1,0,1,2,3};
	vector<double> y={15,5,1,3,11,25};
	double k=0.5;
	cout<<"value of f at 0.5 is: ";
	cout<<fun(x,y,k);
	cout<<endl;
	}

//value of f at 0.5 is: 1.25
