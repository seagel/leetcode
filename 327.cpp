class Solution {
    
    class Node {
    public:
        long st,ed,cnt;
        Node* left;
        Node* right;
            Node(long st,long ed,long cnt){
                this->st = st;
                this->ed = ed;
                this->cnt = cnt;
                this->left = nullptr;
                this->right = nullptr;
            }
    };
    
public:
    
    int query(Node* root,long l,long r){
        if(root == nullptr)
            return 0;
        if(root->st > r || root->ed < l)
            return 0;
        long st = root->st;
        long ed = root->ed;
        if(root->st == l && root->ed == r)
            return root->cnt;
        long mid = st + (ed - st)/2;
        long ans = 0;
        if(mid >= r){
            ans = query(root->left,l,r);
        }else if(mid<l){
            ans = query(root->right,l,r);
        }else{
            ans = query(root->left,l,mid) + query(root->right,mid+1,r);
        }
        return ans;
    }
    
    void update(Node* root,long sum){
        if(root == nullptr)
            return;
        long l = root->st;
        long r = root->ed;
        long mid = l + (r - l)/2;
        if(l == r && mid == sum){
            root->cnt++;
            return;
        }
        if(mid>= sum){
            if(root->left == nullptr){
                root->left = new Node(l,mid,0);
            }
            update(root->left,sum);
        }else{
            if(root->right == nullptr){
                root->right = new Node(mid+1,r,0);
            }
            update(root->right,sum);
        }
        if(root->left && root->right){
            root->cnt = root->left->cnt  + root->right->cnt;
        }else if(root->left){
            root->cnt = root->left->cnt;
        }else{
            root->cnt = root->right->cnt;
        }
        // cout<<root->st<<" "<<root->ed<<" "<<root->cnt<<endl;
    }
    
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans=0, n=nums.size();
        long tmp=0, minV=0, maxV=0, minVal=INT_MAX, maxVal=INT_MIN;
        vector<long> prefixSum;
        prefixSum.push_back(0);
        for(int i=0; i<n; ++i){
            if(nums[i]<minVal)
                minVal=nums[i];
            if(nums[i]>maxVal)
                maxVal=nums[i];
            tmp+=nums[i];
            if(tmp<minV)
                minV=tmp;
            if(tmp>maxV)
                maxV=tmp;
            prefixSum.push_back(tmp);
        }
        if((maxVal<=0 && maxVal<lower) || (minVal>=0 && minVal>upper))
            return 0;
        minV=min(minV,minV-upper);
        maxV=max(maxV,maxV-lower);
        Node* root = new Node(minV, maxV, 0);
        for(int i=0; i<=n; ++i){
            ans+=query(root,prefixSum[i]-upper,prefixSum[i]-lower);
            update(root, prefixSum[i]);
        }
        return ans;
    }
};
