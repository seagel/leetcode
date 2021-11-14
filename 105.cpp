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
    int find(vector<int>& a,int x,int l,int r){
        int ind = -1;
        for(int i=l;i<=r;i++){
            if(a[i] == x){
                ind = i;
                break;
            }
        }
        return ind;
    }
public:
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int l,int r,int* ind){
        // cout<<preorder[*ind]<<" "<<l<<" "<<r<<endl;
        if(l> r)
            return NULL;
        TreeNode* root = new TreeNode(preorder[*ind]);
        (*ind)++;
        if(l== r)
            return root;
        int x = find(inorder,root->val,l,r);
        // cout<<x<<endl;
        root->left = solve(preorder,inorder,l,x-1,ind);
        root->right = solve(preorder,inorder,x+1,r,ind);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int x = 0;
        return solve(preorder,inorder,0,preorder.size()-1,&x);
    }
};
