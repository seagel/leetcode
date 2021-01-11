//
// Created by Somesh Mehta on 28/12/20.
//

#include<iostream>
#include<vector>
using namespace std;
int lower_bound(vector<int>& nums,int l,int r,int x){

    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid] >= x ){
            r = mid;
        }else{
            l=mid+1;
        }
    }
    return nums[l] == 1 ? l : -1;
}
int upper_bound(vector<int>& nums,int l,int r,int x){
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid] > x ){
            r = mid;
        }else{
            l=mid+1;
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
    cout<<lower_bound(a,0,n,1)<<endl;
    cout<<upper_bound(a,0,n,1)<<endl;

}