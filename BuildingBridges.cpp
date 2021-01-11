//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> north(n),south(n);
    for(int i=0;i<n;i++){
        cin>>north[i];
    }
    for(int i=0;i<n;i++){
        cin>>south[i];
    }
    vector<int> dp(n,1);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(north[i] > north[j] &&south[i] > south[j]){
                dp[j] = max(dp[j],dp[i]+1);
            }else if(north[i] < north[j] && south[i] <south[j]){
                dp[j] = max(dp[j],dp[i]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return 0;
}
