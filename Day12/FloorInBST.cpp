/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void find(TreeNode<int> * root, int x, int &mx) {
    if(!root) {
        return;
    }
    if(root->val <= x) {
        mx = max(mx, root->val);
        find(root->right, x, mx);
    }
    else {
        find(root->left, x, mx);
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    int mx = -1;
    find(root, X, mx);
    return mx;
    // Write your code here.
}