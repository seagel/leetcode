//
// Created by Somesh Mehta on 1/6/23.
//

#include <bits/stdc++.h>
using namespace std;
string getOrder(vector<string>& words){
    map<char,int> inDegree;
    map<char,vector<char>> adjList;
    set<char> s;
    for(int i=1;i<words.size();i++){
        string first = words[i-1];
        string second = words[i];
        int length = min(first.length(),second.length());
        for(int j=0;j<length;j++){
            if(first[j]!=second[j]){
                if(adjList.find(first[j]) == adjList.end()){
                    adjList[first[j]] = vector<char>();
                }
                adjList[first[j]].push_back(second[j]);
                inDegree[second[j]]++;
                s.insert(first[j]);
                s.insert(second[j]);
                break;
            }
        }
    }
    queue<char> q;
    for(auto curr : s){
        cout<<inDegree[curr]<<endl;
        if(inDegree[curr]==0){
            q.push(curr);
        }
    }
    string ans = "";
    while(!q.empty()){
        char curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto child : adjList[curr]){
            inDegree[child]--;
            if(inDegree[child]==0){
                q.push(child);
            }
        }
    }
    return ans.length() == s.size() ? ans : "";
}
int main() {
    vector<string> input = {"wrt","wrf","er","ett","rftt"};
    vector<string> input2 = {"z","x"};
    vector<string> input3 = {"z","x","z"};
    cout<<getOrder(input3)<<endl;
    return 0;
}