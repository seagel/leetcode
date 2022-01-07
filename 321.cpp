class Solution {
public:
    vector<int> maxLen(vector<int>& arr,int k){
        vector<int> ans(k,0);
        int j=0,n = arr.size();
        for(int i=0;i<n;i++){
            while((n-i +j) > k && j>0 && arr[i] > ans[j-1]){
                j--;
            }
            if(k > j)
                ans[j++] = arr[i];
        }
        return ans;
    }
    
    bool greater(vector<int>& nums1,vector<int>& nums2,int i,int j){
        while(i< nums1.size() && j <nums2.size() && nums1[i] == nums2[j]){
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    
    vector<int> merge(vector<int>& nums1,vector<int>& nums2,int first,int second){
        vector<int> ele1 = maxLen(nums1,first);
        vector<int> ele2 = maxLen(nums2,second);
        vector<int> ans;
        int i =0,j=0;
        for(int r =0;r<first+second;r++){
            bool result = greater(ele1,ele2,i,j);
            ans.push_back(greater(ele1,ele2,i,j) ? ele1[i++] : ele2[j++]);
        }
     
        return ans;
    }
    
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> tmp,ans(k,0);
        int m = nums2.size();
        int n = nums1.size();
        for(int i=max(0,k-m);i<=k && i<=n ;i++){
            tmp = merge(nums1,nums2,i,k-i);
            if(greater(tmp,ans,0,0)){
                ans = tmp;
            } 
        }
        return ans;
    }
};
