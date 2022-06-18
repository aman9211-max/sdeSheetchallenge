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
void find(TreeNode<int> *root, int &k, int &ans) {
    if(!root) {
        return;
    }
    find(root->left, k, ans);
    k--;
    if(k == 0 and root) {
        ans = root->data;
    }
    find(root->right, k, ans);
    
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    find(root, k, ans);
    return ans;
}