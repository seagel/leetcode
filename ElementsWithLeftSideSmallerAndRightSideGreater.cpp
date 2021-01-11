//
// Created by Somesh Mehta on 07/01/21.
//
#include<vector>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> left(n);
    int maxElement = INT_MIN;
    for(int i=0;i<n;i++){
        maxElement = max(a[i],maxElement);
        left[i] = maxElement;
    }
    int minElement = INT_MAX;
    int ans = -1;
    for(int i=n-1;i>=0;i--){
        if(i==0 && minElement > a[i]){
            ans = i;
            break;
        }else if(i==n-1 && left[n-2] < a[i]){
            ans = i;
            break;
        }else if(left[i-1] < a[i] && minElement > a[i]){
            ans= i;
            break;
        }
        minElement = min(a[i],minElement);

    }
    cout<<ans<<endl;
    return 0;
}

