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
        
void convert(BinaryTreeNode<int>* root,  BinaryTreeNode<int> *&h,  BinaryTreeNode<int> *&t, BinaryTreeNode<int>* &prev) {
    if(!root) {
        return;
    }
    convert(root->left, h, t, prev);
    if(!h and !t) {
        h = t = new BinaryTreeNode<int>(root->data);
    }
    else {
        prev = t;
        t->right = new BinaryTreeNode<int>(root->data);
        t = t->right;
        t->left = prev;
    }
    convert(root->right, h, t, prev);
    
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int> *h, *t, *prev;
    h = t = prev = nullptr;
    convert(root, h, t, prev);
    return h;
    
}