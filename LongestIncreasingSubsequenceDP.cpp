class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> arr;
        int ans = 1;
        for(auto i : nums){
            int temp = distance(arr.begin(),arr.lower_bound(i));
            cout<<temp<<endl;
            ans = max(temp+1,ans);
            arr.insert(i);
        }
        return ans;
    }
};
