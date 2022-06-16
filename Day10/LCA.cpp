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
TreeNode<int> * LCA(TreeNode<int> *root, int x, int y) {
    if(!root) {
        return nullptr;
    }
    if(root->data == x || root->data == y) {
        return root;
    }
    
    auto left = LCA(root->left, x, y);
    auto right = LCA(root->right, x, y);
    
    if(left and right) {
        return root;
    }
    else if(!left) {
        return right;
    }
    return left;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//Write your code here
    return  LCA(root, x, y)->data;
    
}