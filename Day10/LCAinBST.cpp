/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) {
        return nullptr;
    }
    if(root == P || root == Q) {
        return root;
    }
    int val1 = P->data;
    int val2 = Q->data;
    if(val1 < root->data and val2 < root->data) {
        return LCAinaBST(root->left, P, Q);
    }
    else if(val1 > root->data and val2 > root->data) {
        return LCAinaBST(root->right, P, Q);
    }
    return root;
}
