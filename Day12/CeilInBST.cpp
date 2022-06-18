/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
int getCeil(BinaryTreeNode<int> *root, int x) {
    if(!root) {
        return INT_MAX;
    }
    if(root->data >=  x) {
        return min(root->data, getCeil(root->left, x));
    }
    return getCeil(root->right, x);
}

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ans = getCeil(root, x);
    if(ans == INT_MAX) return -1;
    return ans;
}