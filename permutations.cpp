//
// Created by Somesh Mehta on 27/12/20.
//

#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

void permute(vector<int>& arr,int l,int r){
    if(l==r){
        for(int i : arr){
            cout<<i<<" ";
        }
        cout<<endl;
    return;
    }
    for(int i=l;i<=r;i++){
        swap(arr[l],arr[i]);
        permute(arr,l+1,r);
        swap(arr[l],arr[i]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    permute(a,0,n-1);
    return 0 ;
}