/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    public: TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return NULL;
        TreeNode* ans = NULL;
        if(p == root || q == root){
            ans =  root;
        }else if(root->val >= p->val && root->val<= q->val){
            ans = root;
        }else if(root->val >= p->val && root->val >= q->val)
            ans = lowestCommonAncestor(root->left,p,q);
        else if(root->val <= p->val && root->val <= q->val)
            ans = lowestCommonAncestor(root->right,p,q);
        return ans;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            TreeNode* temp = q;
            q = p;
            p =temp;
        }
        return solve(root,p,q);
    }
};
