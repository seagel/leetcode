class Solution {
public:
    
    void solve(int openCnt,int closeCnt,vector<string> &results,string curr){
        if(closeCnt == 0){
            results.push_back(curr);
            return ;
        }
        if(openCnt == closeCnt){
            solve(openCnt-1,closeCnt,results,curr+'(');
        }else if(openCnt < closeCnt){
            if(openCnt >0){
                solve(openCnt-1,closeCnt,results,curr+'(');
            }
            solve(openCnt,closeCnt-1,results,curr + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        solve(n,n,results,"");
        return results;
    }
};
