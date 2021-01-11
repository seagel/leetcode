//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int myCompare(string x,string y){
    string first = x+y;
    string second = y+x;
    return first > second ? 1 : 0;
}
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),myCompare);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}

