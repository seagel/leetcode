class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap; 
        int count =1,curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curr == nums[i]){
                count++;
            }else{
                if(minHeap.size() < k)
                    minHeap.push({count,curr});
                else if(minHeap.size() == k && minHeap.top().first < count){
                    minHeap.pop();
                    minHeap.push({count,curr});
                }
                count=1;
                curr = nums[i];
            }
        }
        
        if(count > 0 ){
            if(minHeap.size() < k)
                    minHeap.push({count,curr});
                else if(minHeap.size() == k && minHeap.top().first < count){
                    minHeap.pop();
                    minHeap.push({count,curr});
                }
        }
        vector<int> results;
        while(!minHeap.empty()){
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return results;
    }
};
