//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int packets;
    cin>>packets;
    vector<int> dp(n+1,INT_MAX);
    int x;
    for(int i=0;i<packets;i++){
        cin>>x;
        dp[x] = 1;
    }
    for(int i=10;i<=n;i++){
        if(i >= 6 && dp[i-6] < INT_MAX){
            dp[i] = min(dp[i] , dp[i-6] + 1);
        }
        if(i>= 9  && dp[i-9] < INT_MAX){
            dp[i] = min(dp[i],dp[i-9] + 1);
        }
        if(i>= 20  && dp[i-20] < INT_MAX){
            dp[i] = min(dp[i],dp[i-20] + 1);
        }
        cout<<dp[i]<<" "<<i<<endl;
    }


    return 0;
}