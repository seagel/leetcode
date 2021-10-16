class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        for(int i=0;i<p.size();i++){
            graph[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }
        queue<int> q;
        queue<int> st;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                st.push(i);
            }
        }
        while(!q.empty()){
            int course = q.front();
            // cout<<course<<endl;
            q.pop();
            for(int i : graph[course]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                        st.push(i);
                }
            }
        }
        
        for(int i:indegree){
            if(i!=0)
                return {};
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.front());
            st.pop();
        }
        return ans;
    }
};

