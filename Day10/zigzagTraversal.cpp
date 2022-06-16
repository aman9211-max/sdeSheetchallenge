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
void reverse_queue(queue<BinaryTreeNode<int> *> & q) {
    vector<BinaryTreeNode<int> *> ans;
    while(!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
   reverse(ans.begin(), ans.end());
    for(auto i : ans) {
        q.push(i);
    }
}
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root) {
        return {};
    }
    // Write your code here!
    int ind = 0;
    queue<BinaryTreeNode<int> *> q;
    
    q.push(root);
    vector<int> ans;
     while(!q.empty()) {
         reverse_queue(q);
         int size = q.size();
         while(size--) {
             auto it = q.front();
             q.pop();
             ans.push_back(it->data);
             if(!(ind & 1)) {
                 if(it->left) {
                     q.push(it->left);
                 }
                 if(it->right) {
                     q.push(it->right);
                 }
             }
             else {
                 if(it->right) {
                     q.push(it->right);
                 }
                 if(it->left) {
                     q.push(it->left);
                 }
             }
         }
         ind ^= 1;
     }    
    return ans;
}
