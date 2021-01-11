//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include <vector>
using namespace std;
int solveIfMultipleBuyingSellingAllowed(vector<int>& a,int n){
    int ans =0;
    bool buy = false;
    for(int i=0;i<n;i++){
        if(!buy && a[i] < a[i+1] ){
            buy = true;
            ans-=a[i];
        }else if(buy && a[i+1] < a[i]){
            buy = false;
            ans+=a[i];
        }
    }
    return ans;
}
int solveIfOnlySellingAndBuyingOnlyOnce(vector<int> &a,int n){
    int ans =0;
    int curr_ans = 0;
    bool buy = false;
    for(int i=0;i<n;i++) {
        if (!buy && a[i] < a[i + 1]) {
            buy = true;
            curr_ans -= a[i];
        } else if (buy && a[i + 1] < a[i]) {
            buy = false;
            curr_ans += a[i];
            ans = max(curr_ans, ans);
            curr_ans = 0;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solveIfOnlySellingAndBuyingOnlyOnce(a,n);
    return 0;
}
