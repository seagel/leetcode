class Solution {
    int dp[1005];
public:
    bool solve(string s, int i, vector<string>& wordDict){
        if(i>=s.length()){
            return true;
        }
        if(dp[i]!=-1)
            return dp[i];
            
        bool result = false;
        for(string tmp : wordDict){
            if(tmp.length() <= s.length()){
                string curr = s.substr(i,tmp.length());
                if(curr == tmp){
                    result = result || solve(s,i+tmp.length(),wordDict);
                }
            }
        }
        dp[i] = result;
        return result;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,wordDict);
    }
};
