class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<long,long> dp;
        map<long,bool> vis;
        for(int i=0;i<nums.size();i++){
            dp[nums[i]] =1;
            vis[nums[i]]= false;
        }
    
        int answer =0;
        for(int i=0;i<nums.size();i++){
            if(vis[nums[i]])
                continue;
            int temp =1;
            int curr_num = nums[i]+1;
            while(dp[curr_num]){
                curr_num++;
                temp++;
                vis[curr_num]=true;
            }
            curr_num = nums[i]-1;
            while(dp[curr_num]){
                curr_num--;
                temp++;
                vis[curr_num]=true;
            }
            answer = max(answer,temp);
        }
        return answer;
    }
};
