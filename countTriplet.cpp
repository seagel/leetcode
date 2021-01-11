//
// Created by Somesh Mehta on 06/01/21.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> freq,vis;
    int maxElement = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxElement = max(maxElement,arr[i]);
        freq[arr[i]]++;
    }

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }



    int ans = 0;
    ans += (freq[0] * (freq[0] -1 ) * (freq[0] -2) ) /6;
    for(auto x : freq){
        if(x.first != 0){
            ans += freq[0] * ((x.second * (x.second - 1 ) )/2);
            ans += ((x.second * (x.second - 1 ) )/2) * freq[2 * x.first];
        }
    }
    for(int i=1;i<=maxElement;i++){
        for(int j=i+1;j<maxElement;j++){
            ans += freq[arr[i]] * freq[arr[j]] * freq[arr[i] + arr[j]];
        }
    }

    cout<<ans<<endl;

    return 0;
}

