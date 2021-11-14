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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<int> maxHeap;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr != NULL){
                if(maxHeap.size() < k)
                maxHeap.push(curr->val);
                else if(maxHeap.size() == k && maxHeap.top() > curr->val){
                    maxHeap.pop();
                    maxHeap.push(curr->val);
                }
                q.push(curr->left);
                q.push(curr->right);
            }
            
        }
        return maxHeap.top();
    }
};
