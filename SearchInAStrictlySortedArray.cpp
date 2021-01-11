//
// Created by Somesh Mehta on 30/12/20.
//

#include<iostream>
#include<vector>
using namespace std;


int binary_search(vector<vector<int>>& arr,int target){
    int n=arr.size(),m=arr[0].size();
    int l =0,r = arr.size()*arr[0].size()-1;
    while(l<r){
        int mid = (l+r)/2;
        if(arr[mid/m][mid%m] == target){
            return mid;
        }else if(arr[mid/m][mid%m] < target){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cin>>target;
    int index = binary_search(a,target);
    cout<<index/m<<""<<index%m<<endl;
    return 0;
}