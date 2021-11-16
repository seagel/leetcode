class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(1000,-1);
        int ans = 0,curr = 0;
        for(int i=0;i<s.length();i++){
            if(count[s[i]] != -1){
                int tmp = count[s[i]];
                for(int j=0;j<257;j++){
                    if(count[j] <=tmp && count[j]>=0){
                        count[j] = -1;
                        curr--;
                    }
                }
            }
            curr++;
            count[s[i]] = i;
            // cout<<curr<<" "<<ans<<endl;
            ans = max(ans,curr);
        }
        return ans;
    }
};
