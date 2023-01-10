//
// Created by Somesh Mehta on 1/10/23.
//

// This is the follow-up solution of Kth largest element in Leetcode.
// I am storing the size of the subtree(including the parent) in each node so that the calculation of kth element in
// faster and we can directly some subtree.
#include <iostream>

using namespace std;
class Node {
public :
    int val;
    Node* left;
    Node* right;
    int size;
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
        this->size = 1;
    }
};
class Tree{
private:
    Node* insertInternal(Node* root,int val){
        if(root == nullptr){
            return new Node(val);
        }
        if(root->val > val){
            root->left = insertInternal(root->left,val);
        }else{
            root->right = insertInternal(root->right,val);
        }
        root->size = root->left->size + root->right->size + 1;
        return root;
    }
    void inorderInternal(Node* root){
        if(root == nullptr){
            return;
        }
        inorderInternal(root->left);
        cout<<root->val<<" Size:"<<root->size<<endl;
        inorderInternal(root->right);
    }
public:
    Node* root;
    Tree(){
        this->root = nullptr;
    }

    void insert(int val){
        this->root = insertInternal(root,val);
    }
    void inorder(){
        inorderInternal(root);
    }

};
int main(){
    Tree bst;
    bst.insert(2);
    bst.insert(3);
    bst.inorder();
    return 0;
}