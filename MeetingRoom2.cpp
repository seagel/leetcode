//
// Created by Somesh Mehta on 31/12/20.
//
#include<iostream>
#include<vector>
#include<map>
#include <queue>

using namespace std;

int solve(vector<pair<int,int>>& arr, int n){
    map<int,int> order;
    for(int i=0;i<n;i++){
        order[arr[i].first] +=1;
        order[arr[i].second]-=1;
    }
    int ans = 0,curr=0;
    for(auto i : order){
        curr+= i.second;
        ans=max(ans,curr);
    }
    cout<<ans;
    return ans;
}

int solve_priorityQueue(vector<pair<int,int>>& arr, int n){
    if(arr.size() == 0){
        return 0;
    }
    sort(arr.begin(),arr.end());
    priority_queue<int,vector<int>,greater<>> q;
    q.push(arr[0].second);
    for(int i=1;i<n;i++){
        if(q.top() <= arr[i].first){
            q.pop();
        }
        q.push(arr[i].second);
        cout<<q.size()<<endl;
    }
    return q.size();
}


 int main(){
     int n;
     cin>>n;
     vector<pair<int,int>> arr(n);
     for(int i=0;i<n;i++){
         int first,second;
         cin>>first>>second;
         arr[i] =make_pair(first,second);
     }
     cout<<solve_priorityQueue(arr,n);
     return 0;
 }
