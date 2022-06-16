/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
map<int, int> m;
int indx = 0;
TreeNode<int> *dfs(vector<int> &in, vector<int> &post, int i, int j) {
    
    if(i > j) {
        return nullptr;
    }
    
    int pos = m[post[indx]]; 
    TreeNode<int> * n = new TreeNode<int>(post[indx++]);
    n->right = dfs(in, post, pos + 1, j);
    n->left = dfs(in, post, i, pos - 1);
    
    return n;
    
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    reverse(postOrder.begin(), postOrder.end());
    for(int i = 0; i < inOrder.size(); i++) {
        m[inOrder[i]] = i;
    }
    TreeNode<int> * n = dfs(inOrder, postOrder, 0, inOrder.size() - 1);
    m.clear();
    indx = 0;
    return n;
    
}
