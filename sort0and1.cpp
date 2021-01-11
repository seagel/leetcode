//
// Created by Somesh Mehta on 27/12/20.
//

#include<iostream>
#include<iosfwd>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low =0 ,high = n-1,mid = 0;
    while(mid <= high){
        switch (a[mid]) {
            case 0:
                swap(a[low],a[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid],a[high]);
                high = high -1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}