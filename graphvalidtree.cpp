//
// Created by Somesh Mehta on 11/2/21.
//

#include <bits/stdc++.h>
using namespace std;
int find(int x,vector<int> &parent){
    if(parent[x] =-1)
        return x;
    return find(parent[x],parent);
}
void union1(int x,int y,vector<int> &p){
    p[x]=y;
}


bool isCycle(int n,vector<pair<int,int>> edges){
    vector<int> parent(n,-1);
    for(int i=0;i<edges.size();i++){
        int x = find(edges[i].first,parent);
        int y= find(edges[i].second,parent);
        if(x==y)
            return true;
        union1(x,y,parent);
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int n_edges;
    cin>>n_edges;
    vector<pair<int,int>> edges;
    for(int i=0;i<n_edges;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    cout<<isCycle(n,edges);
    return 0;
}