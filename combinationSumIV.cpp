class Solution {
    int dp[1005];
public:
    int solve(vector<int>& nums,int target){
        if(target == 0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int ans = 0;
        for(int num : nums){
            if(target - num >=0){
                ans+=solve(nums,target - num);
            }
        }
        dp[target] = ans;
        return ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);
    }
};
