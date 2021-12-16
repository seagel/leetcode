class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count(nums.begin(),nums.end());
        int result =0;
        while(count.size() > 0){
            int first = *count.begin();
            int left = first-1,right = first+1;
            count.erase(first);
            while(count.find(left)!=count.end()){
                count.erase(left);
                left--;
            }
            while(count.find(right)!=count.end()){
                count.erase(right);
                right++;
            }
            result = max(right-left-1,result);
        }
        return result;
    }
};
