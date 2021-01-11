//
// Created by Somesh Mehta on 07/01/21.
//

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxElement = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > maxElement){
            cout<<arr[i]<<" ";
            maxElement = arr[i];
        }
    }
    return 0;
}