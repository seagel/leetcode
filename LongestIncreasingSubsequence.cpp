//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int solveByDynamicProgramming(vector<int> &arr,int n){
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[i]){
                dp[j] = max(dp[i]+1,dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int solveBySet(vector<int> &arr,int n){
    set<int> st;
    for(int i=0;i<n;i++){
        if(st.lower_bound(arr[i]) == st.end())
        {
            st.insert(arr[i]);
        }else{
            auto it = st.lower_bound(arr[i]);
            st.erase(it);
            st.insert(arr[i]);
        }
    }
    return st.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solveBySet(arr,n);
    return 0;
}
