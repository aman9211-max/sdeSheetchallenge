/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &ans) {
    if(!root) {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void preorder(BinaryTreeNode<int> * root, vector<int> &ans) {
    if(!root) {
        return;
    }
    
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
void postorder(BinaryTreeNode<int> * root, vector<int> &ans) {
    if(!root) {
        return;
    }
    
    
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    
    vector<int> ans;
    vector<vector<int> > res;
    
    inorder(root, ans);
    res.push_back(ans);
    ans.clear();
    preorder(root, ans);
    res.push_back(ans);
    ans.clear();
    postorder(root, ans);
    res.push_back(ans);
    return res;
}