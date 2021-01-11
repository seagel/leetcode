//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int currMax = arr[0],maxConsolidated = arr[0];
    int currStart = 0 , startWhole =0 ,startEnd =0;
    for(int i=1;i<n;i++){
        currMax += arr[i];
        if(arr[i] > currMax){
            currMax = arr[i];
            currStart = i;
        }else if(currMax > maxConsolidated){
            maxConsolidated = currMax;
            startWhole = currStart;
            startEnd = i;
        }
    }
    if(currMax > maxConsolidated){
        maxConsolidated = currMax;
        startWhole = currStart;
        startEnd = n-1;
    }
    cout<<startWhole<<" "<<startEnd<<endl;
    return 0;
}
