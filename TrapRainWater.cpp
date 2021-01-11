//
// Created by Somesh Mehta on 07/01/21.
//

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> left(n),right(n);
    int maxElement =INT_MIN;
    for(int i=0;i<n;i++){
        maxElement = max(maxElement,a[i]);
        left[i]= maxElement;
    }
    maxElement = INT_MIN;
    for(int i=n-1;i>=0;i--){
        maxElement = max(maxElement,a[i]);
        right[i]= maxElement;
    }
    int ans =0;
    for(int i=0;i<n;i++){
        ans += min(left[i],right[i]) - a[i];
    }
    cout<<ans;
    return 0;
}