//
// Created by Somesh Mehta on 29/12/20.
//

#include<iostream>
#include<vector>
using namespace std;

//int binary_search(vector<int>& nums,int l,int r,int target){
//    if(l>r){
//        return -1;
//    }
//    int mid = (l+r)/2;
//    if(nums[mid] == target){
//        return mid;
//    }
//    if(nums[mid] >=nums[l] ){
//        if(target >= nums[l] && target <= nums[mid]){
//            return binary_search(nums,l,mid-1,target);
//        }else{
//            return binary_search(nums,mid+1,r,target);
//        }
//    }
//    if(target >=nums[mid] && target <= nums[r]){
//        return binary_search(nums,target,mid+1,r);
//    }
//    return binary_search(nums,target,l,mid-1);
//}

int binary_search(vector<int> &nums,int l,int r,int target){
    while(l<r){
        int mid = (l+r)/2;
        if(nums[mid] >= target){
            r =mid;
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
    cout<<binary_search(a,0,n,5);
}