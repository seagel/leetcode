//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int solve(string x,string y,int i,int j){
    if(i >= x.length() || j >= y.length()){
        return 0;
    }
    if(x[i] == y[j]){
        return 1 + solve(x,y,i+1,j+1);
    }
    return max(solve(x,y,i+1,j) ,solve(x,y,i,j+1));
}
int main(){
    string x,y;
    cin>>x>>y;
//    cout<<solve(x,y,0,0);
    vector<vector<int>> dp(x.length()+1,vector<int>(y.length()+1,0));
    for(int i=0;i<=x.length();i++){
        for(int j=0;j<=y.length();j++){
            if(i==0 || j==0){
                dp[i][j] =0;
            }else if(x[i-1] == y[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[x.length()][y.length()];
    return 0;
}

