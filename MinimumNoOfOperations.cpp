//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    dp[1] = 0;
    dp[2] =1;
    for(int i=3;i<=n;i++){
        if(i%3 ==0){
            dp[i] = min(dp[i/3] + 1,dp[i]);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + 1,dp[i]);
        }
        dp[i] = min(dp[i] ,dp[i-1] + 1);
    }
    cout<<dp[n];


    return 0;
}
