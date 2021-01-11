//
// Created by Somesh Mehta on 06/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> & arr,int maxElement){
    int minIndex = 0 ,maxIndex = arr.size() -1;
    for(int i=0;i<arr.size();i++){
        if(i % 2!=0){
            arr[i] += (arr[minIndex] % maxElement) * maxElement;
            minIndex++;
        }else{
            arr[i] += (arr[maxIndex] % maxElement) * maxElement;
            maxIndex--;
        }
    }
    for(int & i : arr){
        i =i /maxElement;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxElement = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxElement = max(arr[i],maxElement);
    }
    maxElement = maxElement +1;
    solve(arr,maxElement);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
//    vector<int> ans;
//    int l =0 ,r=n-1;
//    while(l <r){
//        ans.push_back(arr[r]);
//        ans.push_back(arr[l]);
//        r--;
//        l++;
//    }
//    for(auto i : ans){
//        cout<<i<<" ";
//    }
//    cout<<endl;

    return 0;
}
