/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> * flatted(TreeNode<int> *root) {
    if(!root) {
        return nullptr;
    }
    TreeNode<int> * n = new TreeNode<int> (root->data);
    n->right = flatted(root->left);
    TreeNode<int> * t = n;
    while(t->right) {
        t = t->right;
    }
    t->right = flatted(root->right);
    return n;
    
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    return flatted(root);
}