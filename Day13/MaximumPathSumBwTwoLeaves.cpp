
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int find_sum(TreeNode<int> *root, long long int &ans) {
    if(!root) {
        return 0LL;
    }
    long long int left = find_sum(root->left, ans);
    long long int right = find_sum(root->right, ans);
    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    
    while(root and !root->left) {
        root = root->right;
    }
    while(root and !root->right) {
        root = root->right;
    }
    
    if(!root) {
        return -1;
    }
    
    if(!root->left and !root->right) {
        return root->val;
    }
    
    long long int ans = 0;
    long long int t = find_sum(root, ans);
    return ans;
}