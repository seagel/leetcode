class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dpWithoutLast(nums.size()+1,0),dpWithLast(nums.size()+1,0);
        dpWithoutLast[1] = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            dpWithoutLast[i+1] = max(dpWithoutLast[i],dpWithoutLast[i-1]+nums[i]);
        }
        dpWithLast[2] = nums[1];
        for(int i=2;i<nums.size();i++){
            dpWithLast[i+1] = max(dpWithLast[i],dpWithLast[i-1]+nums[i]);
        }
        return max(dpWithoutLast[nums.size()-1],dpWithLast[nums.size()]);
      }
};
