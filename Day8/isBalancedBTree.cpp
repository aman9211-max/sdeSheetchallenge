/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
class Pair {
    public:
    bool isBalanced;
    int height;
};

Pair isBalanced(BinaryTreeNode<int> * root) {
    Pair p;
    if(!root) {
        p.isBalanced = true;
        p.height = 0;
        return p;
    }
    
    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);
    
    p.height = 1 + max(left.height, right.height);
    bool op1 = (abs(left.height - right.height) <= 1) ? true : false;
    bool op2 = left.isBalanced;
    bool op3 = right.isBalanced;
    p.isBalanced = (op1 and op2 and op3);
   return p;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return isBalanced(root).isBalanced;
}