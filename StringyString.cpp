//
// Created by Somesh Mehta on 09/01/21.
//
#include<iostream>
#include<vector>
#include "unordered_map"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    unordered_map<int,int> freq;
    vector<int> sum(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<a[i].length();j++){
            sum[i]+=a[i][j] - 'a' +1;
        }
    }
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                temp.push_back(sum[j]);
            }
        }
        sort(temp.begin(),temp.end());
        int mid1 = temp.size()/2;
        int mid2 =temp.size()/2 -1;
        int curr_sum = 0;
        for(int j=0;j<temp.size();j++){
            curr_sum+=abs(temp[j] - temp[mid1]);
        }
        cout<<curr_sum<<" "<<endl;
        freq[curr_sum] = i;
        curr_sum = 0;
        for(int j=0;j<temp.size();j++){
            curr_sum+=abs(temp[j] - temp[mid2]);
        }
        cout<<curr_sum<<" "<<endl;
        cout<<"This chance done"<<endl;
        freq[curr_sum] = i;
        temp.clear();

    }
    int mini = INT_MAX ,index = -1;
    for(auto x : freq){
        if(mini > x.first){
            mini = x.first;
            index = x.second;
        }
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<a[index]<<endl;

    return 0;
}
