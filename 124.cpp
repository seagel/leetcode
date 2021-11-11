/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public: static int answer;
    int solve(TreeNode* root,int *answer){
        if(root == NULL)
            return 0;
        int left = solve(root->left,answer);
        int right = solve(root->right,answer);
        *answer = max(root->val,*answer);
        *answer = max(root->val+left,*answer);
        *answer = max(root->val+right,*answer);
        *answer = max(root->val+left+right,*answer);
        return max(max(left,right) + root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int answer =INT_MIN;
        solve(root,&answer);
        return answer;
    }
    
};
