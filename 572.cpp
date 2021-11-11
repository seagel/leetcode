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
    
public:
    bool isSame(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        if((root1== NULL && root2!=NULL) || (root1 !=NULL && root2 == NULL)){
            return false;
        }
        return root1->val == root2->val && isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL)
            return false;
        if((root== NULL && subRoot!=NULL) || (root !=NULL && subRoot == NULL)){
            return false;
        }
        bool ans = false;
        if(root->val == subRoot->val){
            ans = ans || isSame(root,subRoot);
        }
        return ans || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
