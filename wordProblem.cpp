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
        vector<bool> dp(s.length()+1,false);
        dp[s.length()] = true;
        for(int i=s.length()-1;i>=0;i--){
            for(string tmp : wordDict){
                if(i+tmp.length() <=s.length() ){
                    string curr = s.substr(i,tmp.length());
                    // cout<<curr<<" "<<i<<endl;
                    if(curr == tmp){
                        dp[i] = dp[i+tmp.length()];
                    }
                    if(dp[i]==1){
                        break;
                    }
                }
                
            }
        }
        // for(int i=0;i<dp.size();i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[0];
    }
