//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int solve(string s,int i,int j){
    if(i== j){
        return 1;
    }else if(i+1 == j && s[i] == s[j]){
        return 2;
    }else if(s[i] == s[j]){
        return 2 + solve(s,i+1,j-1);
    }
    return max(solve(s,i+1,j),solve(s,i,j-1));
}
int main(){
    string s;
    cin>>s;
//    cout<<solve(s,0,s.length() -1);
    vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
    for(int i=1;i<s.length();i++){
        dp[i][i] =1 ;
    }

    for(int len=2;len<=s.length();len++){
        for(int i=0;i<s.length() - len +1;i++){
            int j = i + len -1;
            if(len == 2 &&s[i] == s[j]){
                dp[i][j] =2;
            }else if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }else{
                dp[i][j] =max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][s.length()-1];

    return 0;
}