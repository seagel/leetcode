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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(new TreeNode(-200));
        vector<int> result;
        int val;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == -200){
                result.push_back(val);
                if(!q.empty())
                    q.push(new TreeNode(-200));
            }
            val = curr->val;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return result;
    }
};
