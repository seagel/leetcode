class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() ==1){
            return;
        }
        int ind = nums.size()-1;
        while(ind > 0){
            if(nums[ind] > nums[ind-1])
            {
                break;
            }
            ind--;
        }
        
        if(ind == 0){
            sort(nums.begin(),nums.end());
        }else{
            int swapNumber = ind;
            int curr = ind+1;
             while(curr < nums.size()){
                if(nums[curr] < nums[swapNumber] && nums[curr] > nums[ind-1]){ 
                    swapNumber = curr;
                }
                 curr++;
            }
            swap(nums[swapNumber],nums[ind-1]);
            auto it = nums.begin();
            advance(it,ind);
            sort(it,nums.end());
        }
    }
};
