//
// Created by Somesh Mehta on 26/12/20.
//

#include<iostream>
#include<vector>
#include <cmath>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int limit = pow(2,n);
    vector<int> temp;
    for(int i=0;i<limit;i++){
        for(int j=0;j<a.size();j++){
            int numberWithIthBitSet;
            numberWithIthBitSet = 1 << j;
            if ((i & numberWithIthBitSet) != 0) {
                temp.push_back(a[j]);
            }
        }
        for(int j=0;j<temp.size();j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
        temp.clear();
    }
    return 0 ;
}