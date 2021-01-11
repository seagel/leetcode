//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
#include "map"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> arrival(n),departure(n);
    map<string,int> freq;
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        freq[arrival[i]] = 1;
    }
    for(int i=0;i<n;i++){
        cin>>departure[i];
        freq[departure[i]] = -1;
    }
    int ans = 0;
    int curr = 0;
    for(auto it : freq){
        cout<<it.first<<" ";
        curr += it.second;
        ans = max(curr,ans);
    }
    cout<<ans<<endl;

    return 0;
}
