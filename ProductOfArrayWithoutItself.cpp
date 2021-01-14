//
// Created by Somesh Mehta on 14/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
vector<int> solveWithoutUsingDivision(vector<int> &nums){
    int n = nums.size();
    if(n==0){
        return {0};
    }
    vector<int> dpLeft(n);
    dpLeft[0] = nums[0];
    for(int i=1;i<n;i++){
        dpLeft[i] = dpLeft[i-1] * nums[i];
    }
    vector<int> dpRight(n);
    dpRight[n-1] = nums[n-1];
    for(int i = n-2;i>=0;i--){
        dpRight[i] = dpRight[i+1]*nums[i];
    }
    vector<int> ans(n);
    ans[0] = dpRight[1];
    ans[n-1]=dpLeft[n-2];
    for(int i=1;i<=n-2;i++){
        ans[i] = dpLeft[i-1]*dpRight[i+1];
    }
    return ans;
}

vector<int> productExceptSelfWithDivision(vector<int>& nums) {
    long long productWhole = 1;
    int zeroCount = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 0){
            zeroCount++;
        }else{
            productWhole = productWhole*nums[i];
        }
    }
    vector<int> ans(nums.size(),0);
    if(zeroCount > 1){
        return ans;
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i] !=0){
            if(zeroCount >0){
                ans[i]= 0;
            }else{
                ans[i] = productWhole/nums[i];
            }
        }else{
            ans[i] = productWhole;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    productExceptSelfWithDivision(arr)
    return 0;
}
