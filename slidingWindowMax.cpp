class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> results;
        set<pair<int,int>> window;
        int i = 0;
        for(i=0;i<k;i++)
            window.insert({nums[i],i});
        results.push_back(window.rbegin()->first);
        while(i<nums.size()){
            while(!window.empty() && window.rbegin()->second <= (i-k))
                window.erase(std::prev(window.end()));
            window.insert({nums[i],i});
            results.push_back(window.rbegin()->first);
            i++;
        }
        return results;
    }
};
