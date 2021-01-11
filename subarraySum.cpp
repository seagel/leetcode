//
// Created by Somesh Mehta on 06/01/21.
//

#include<iostream>
#include "vector"
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    int l=0,currSum=0;
    for(int i=0;i<n;i++){
        while(currSum > sum && l< i ){
            currSum = currSum - arr[l];
            l++;
        }
        if(currSum == sum){
            cout<<l<<" "<<i-1<<endl;
            break;
        }
        if(i < n){
            currSum +=arr[i];
        }

    }
    return 0;
}