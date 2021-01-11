//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int findFirstMisMatchCharacter(string a,string b){
    int ans = -1;
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i] != b[i]){
            ans = i;
            break;
        }
    }
    return ans;
}
void topologicalSort(vector<vector<int>> &graph,vector<int> &vis,int node){
    vis[node] = 1;
    for(int i=0;i<graph[node].size();i++){
        if(vis[graph[node][i]] == 0){
            topologicalSort(graph,vis,graph[node][i]);
        }
    }
    char ans = node + 'a';
    cout<<ans<<" ";
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> vis(n,1);

    for(int i=0;i<n-1;i++){
        string first = arr[i];
        string second = arr[i+1];
        int index = findFirstMisMatchCharacter(first,second);
        if(index == -1){
            cout<<"Invalid Sequence Not Possible";
            exit(1);
        }else{
            graph[second[index] - 'a'].push_back(first[index] -'a');
            vis[second[index] - 'a'] = 0;
            vis[first[index] - 'a'] = 0;
        }
    }
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            topologicalSort(graph,vis,i);
        }

    }

    return 0;
}

