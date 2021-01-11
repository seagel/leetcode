//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    while(i<n){
        if(a[i] <= 0){
            i++;
            continue;
        }
        int index = a[i] -1;
        if(a[index] > 0){
            a[i] = a[index];
            a[index] = -1;
        }else{
            a[index]--;
            a[i] = 0;
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<i+1 <<" "<<abs(a[i])<<endl;
    }
    return 0;
}
