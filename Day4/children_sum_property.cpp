/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void dfs(BinaryTreeNode<int> *root) {
     if(!root) {
        return;
    }
    
    
    int t = 0;
    if(root->left) {
       t += root->left->data;
    }
    if(root->right) {
        t += root->right->data;
    }
   if(t >= root->data) {
       root->data = t;
   }
    else {
      
        if(root->right) {
            root->right->data = root->data;
        }
        if(root->left) {
            root->left->data = root->data;
        }
        
        
    }
//     cout << root->data << endl;
    dfs(root->left);
    dfs(root->right);
    int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        if(root->left || root->right) root->data = sum;
        
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
   dfs(root);
    
}  