//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int upper_bound(vector<int> &arr,int x,int l,int r){
    if(l>r){
        return -1;
    }
    while(l <r){
        int mid = (l+r)/2;
        if(arr[mid] >x){
            r = mid;
        }else{
            l =mid+1;
        }
    }
    return l;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int index = 0;
    int x;
    while(index < n){
        x = a[index];
        int noUpperBound = upper_bound(a,x,index,n);
        cout<<"Element "<<a[index]<<" occurs "<<noUpperBound - index<<" times."<<endl;
        index = noUpperBound;
    }
    return 0;
}
