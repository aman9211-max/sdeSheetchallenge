/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
map<int, int> m;
int indx = 0;
TreeNode<int> * build(vector<int> &in, vector<int> &pre, int i, int j) {
    if(i > j) {
        return nullptr;
    }
    
    int pos = m[pre[indx]];
    TreeNode<int> * n = new TreeNode<int>(pre[indx++]);
    n->left = build(in, pre, i, pos - 1);
    n->right = build(in, pre, pos + 1, j);
    return n;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	for(int i = 0; i <inorder.size(); i++) {
        m[inorder[i]] = i;
    }
    
    auto ans = build(inorder, preorder, 0, inorder.size()  - 1);
    m.clear();
    indx = 0;
    return ans;
}