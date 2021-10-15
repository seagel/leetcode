class Solution {   
    
// public:
//     void dfs(vector<vector<int>>& p,vector<int> &vis,int course,vector<int> &instack){
//         vis[course]=1;
//         instack[course]=1;
//         for(int i=0;i<p[course].size();i++){
//             if(vis[p[course][i]] == 0 && instack[p[course][i]]==0)
//                 dfs(p,p[course][i],vis);
//             else
//                 break;
//         }
//         instack[course]=0;
//     }
    
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<p.size();i++){
            graph[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int course = q.front();
            cout<<course<<endl;
            q.pop();
            for(int i : graph[course]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        for(int i:indegree){
            if(i!=0)
                return false;
        }
        return true;
    }
};
