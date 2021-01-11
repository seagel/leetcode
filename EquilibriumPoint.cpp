//
// Created by Somesh Mehta on 06/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int curr_sum =0;
    for(int i=0;i<n;i++){
        if(curr_sum == sum - curr_sum - arr[i]){
            cout<<i<<endl;
            break;
        }
        curr_sum =curr_sum +arr[i];
    }

    return 0;
}
