//
// Created by Somesh Mehta on 06/01/21.
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int> s1;
    int count = 0;
    for(int i=0;i<n;i++){
        auto it = s1.lower_bound(arr[i]);
        count += distance(it,s1.end());
        s1.insert(arr[i]);

    }
    cout<<count<<endl;
    return 0;
}