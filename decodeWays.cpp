class Solution {
    int dp[105];
public:
    int solve(string s,int index){
        if(index==s.length()){
            return 1;
        }
        if(dp[index]!=-1)
            return dp[index];
        int ans=0;
        for(int i=1;i<=2;i++){
            if(index+i >s.length())
                continue;
            string curr = s.substr(index,i);
            //cout<<curr<<endl;
            int number = 0;
            if(i==1){
                number+=curr[1] - '0';
            }else{
                number+=curr[1] - '0';
                number+=10*(curr[0] - '0'); 
            }
            if(curr[0] != '0' && number < 27){
                ans+=solve(s,index+i);
            }
        }
        dp[index] =ans;
        return ans;
    }
    
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};
