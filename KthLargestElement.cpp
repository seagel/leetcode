//
// Created by Somesh Mehta on 28/12/20.
//

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int quicksortPartition(vector<int> &arr, int l, int r) {
    int i=l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= arr[r]) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
void kthLargest(vector<int>& arr,int l,int r,int k){

    int pivot = quicksortPartition(arr,l,r);
    if(pivot == k){
        cout<<arr[pivot]<<endl;
        for(int i=k;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }else if(pivot < k){
        return kthLargest(arr,pivot+1,r,k);
    }
    return kthLargest(arr,l,pivot-1,k);

}


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>arr[i];
    }
//    vector<pair<int,int>> arr;
//    for(auto [k,v] : count){
//        arr.push_back({k,v});
//    }
     kthLargest(arr,0,arr.size()-1,arr.size() - k);
//    for(auto [k,v] : ans){
//        cout<<v<<" ";
//    }
//    cout<<endl;
    return 0;
}