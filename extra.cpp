
#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int fun(vector<int> nums){
    //vector<int> vec(nums.size());
    //vec[0]=nums[0];
    int vec=INT_MAX;
    int ans=0;
    for(int i=1;i<nums.size();i++){
        vec=min(vec,nums[i]);
        ans=max(ans,nums[i]-vec);
    }
    return ans;
}

int main(){
    vector<int> a = {7,1,5,3,6,4};
    long long k = 1;
    int len = fun(a);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}