class Solution {
public:
    
    void solve(TreeNode* root,int& k,int& ans){
        if(root == nullptr)
            return;
        
        solve(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val;
        }
        if(k> 0)
            solve(root->right,k,ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        solve(root,k,ans);
        return ans;
    }
};
