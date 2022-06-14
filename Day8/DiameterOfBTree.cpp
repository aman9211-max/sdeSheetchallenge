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
class Pair {
    public:
    int diameter;
    int height;
};
Pair diameter(TreeNode<int> *root) {
    Pair p;
    if(!root) {
        p.height = p.diameter = 0;
        return p;
    }
    
    Pair left = diameter(root->left);
    Pair right = diameter(root->right);
    p.height = 1 + max(left.height, right.height);
    int op1 = left.diameter;
    int op2 = right.diameter;
    int op3 = left.height + right.height;
    p.diameter = max({op1, op2, op3});
    return p;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    return diameter(root).diameter;
}
