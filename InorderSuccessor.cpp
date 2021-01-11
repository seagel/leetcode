//
// Created by Somesh Mehta on 26/12/20.
//
#include<iostream>
#include "stack"
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    public: TreeNode(int x){
        this->val = x;
        this->left =nullptr;
        this->right =nullptr;
    }
};

class BST {
    TreeNode* head;

    public: BST(){
        head = nullptr;
    }
    public: BST* add(int x){
        if(head == nullptr){
            this->head = new TreeNode(x);
        }else{
            insert(head,x);
        }
        return this;
    }
    private: void insert(TreeNode* root,int x){
        if(root == nullptr){
            return;
        }
        if(root->val >x){
            if(root->left != nullptr){
                insert(root->left,x);
            }else{
                root->left = new TreeNode(x);
            }
        }else{
            if(root->right != nullptr){
                insert(root->right,x);
            }else{
                root->right = new TreeNode(x);
            }
        }
    }
public: BST* inorderTraversal(){
         printInorder(this->head);
         return this;
    }
private: void printInorder(TreeNode* root){
        if(root == nullptr || root == NULL){
            return;
        }
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
private: TreeNode* find(TreeNode* root,int x){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == x){
            return root;
        }else if(root->val > x){
            return find(root->left,x);
        }
        return find(root->right,x);
    }

private: TreeNode* findIfValueInLeft(TreeNode* root,int x){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val > x){
            return root;
        }
        return findIfValueInLeft(root->right,x);
    }
public: int inorderSuccessor(int x){
        if(head == nullptr){
            return -1;
        }
        TreeNode* expectedNode = find(this->head,x);
        if(expectedNode->right != nullptr){
            expectedNode = expectedNode->right;
            while(expectedNode->left != nullptr){
                expectedNode = expectedNode->left;
            }
            return expectedNode->val;
        }else{
            TreeNode* node = findIfValueInLeft(this->head,x);
            return node ? node->val: -1;
        }

    }
private: int kthElementHelper(TreeNode* root,int count){
        if(root == nullptr){
            return 0;
        }

        int leftNodes = kthElementHelper(root->left,count);
        if(leftNodes == count - 1){
            cout<<root->val<<endl;
        }
        int rightNodes = kthElementHelper(root->right,count - leftNodes -1 );

        return leftNodes+rightNodes+1;
    }

public: int kthSmallestElement(int k){
        return kthElementHelper(this->head,k);
    }

private:
    void printBoundaryHelper(TreeNode *root) {
        if(root == nullptr){
            return;
        }
        cout<<root->val<<" ";
        printBoundaryLeft(root->left);
        printLeavesInInorder(root->left);
        printLeavesInInorder(root->right);
        printBoundaryRight(root->right);
    }
private: void printBoundaryLeft(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left){
            cout<<root->val<<" ";
            printBoundaryLeft(root->left);
        }else if(root->right){
            cout<<root->val<<" ";
            printBoundaryLeft(root->right);
        }

    }

private: void printBoundaryRight(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->right){
            printBoundaryLeft(root->right);
            cout<<root->val<<" ";
        }else if(root->left){
            printBoundaryLeft(root->left);
            cout<<root->val<<" ";
        }

    }


public:void printBoundary(){
        TreeNode* root = this->head;
        printBoundaryHelper(root);

    }

public: void printLeavesInInorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        printLeavesInInorder(root->left);
        if(!root->left && !root->right){
            cout<<root->val<<" ";
        }
        printLeavesInInorder(root->right);

    }
};

int main(){
    BST binaryTree = *new BST();
    binaryTree.add(20)->add(8)->add(12)->add(14)->add(26)->add(21)->add(25);
    binaryTree.printBoundary();
    return 0;
}
