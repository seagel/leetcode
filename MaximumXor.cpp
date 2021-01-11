//
// Created by Somesh Mehta on 09/01/21.
//

#include<iostream>
#include<vector>
#include "stack"
using namespace std;
long long turnOffK(long long n, int k)
{
    // k must be greater than 0
    if (k <= 0) return n;

    // Do & of n with a number with all set bits except
    // the k'th bit
    return (n & ~(1 << (k - 1)));
}
int main(){
//    int n;
//    cin>>n;
//    int sum = 0;
//    int x;
//    while(n--){
//        cin>>x;
//        sum = sum^x;
//    }
//    stack<int> st;
//    while(sum>0){
//        st.push(sum%2);
//        sum = sum /2;
//    }
//     long long ans = 1LL << 32;
//    while(!st.empty()){
//        int x = st.top();
//        ans = turnOffK(ans,st.size());
//        st.pop();
//    }
    cout<<(1 << (5 - 1));
//    cout<<ans;



    return 0;
}