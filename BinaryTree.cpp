//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    public: Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool findNode(Node* head,int x){
    if(head== nullptr){
        return false;
    }
    if(head->val == x){
        return true;
    }
    bool leftAns = findNode(head->left,x);
    bool rightAns = findNode(head->right,x);
    return leftAns || rightAns;
}

Node* inorderSuccessor(Node* head,int x,int y){
    if(head == nullptr){
        return nullptr;
    }
    if(head->val == x || head->val == y){
        return head;
    }
    bool nodeInLeft = findNode(head->left,x);
    bool nodeInRight = findNode(head->left,y);
    if(nodeInLeft && nodeInRight){
        return inorderSuccessor(head->left,x,y);
    }else if(!nodeInRight && !nodeInLeft){
        return inorderSuccessor(head->right,x,y);
    }
    return head;
}




int main(){
    Node* head = new Node(1);
    head->left = new Node(3);
    head->right = new Node(2);
    head->left->left = new Node(4);
    head->left->right = new Node(2);
    head->right->left = new Node(7);
    head->right->right = new Node(9);
    cout<<inorderSuccessor(head,1,9)->val;
    return 0;
}
