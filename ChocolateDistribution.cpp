//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans = INT_MAX;
    for(int i=0;i<=n-m;i++){
        ans = min(ans,a[i+m-1] - a[i]);
    }
    cout<<ans<<endl;

    return 0;
}
