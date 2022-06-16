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

bool validateBST(BinaryTreeNode<int> *root, int mi = INT_MIN, int mx = INT_MAX) {
    // Write your code here
    if(!root) {
        return true;
    }
    if(root->data < mi || root->data >  mx) {
        return false;
    }
    return validateBST(root->left, mi, root->data) and validateBST(root->right, root->data, mx);
}