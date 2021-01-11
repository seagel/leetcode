//
// Created by Somesh Mehta on 06/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans = ans ^ a[i];
    }
    for(int i=1;i<=n+1;i++){
        ans = ans ^ i;
    }

    cout<<ans<<endl;


    return 0;
}

