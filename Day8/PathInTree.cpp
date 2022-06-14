/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
 vector<int> res;

void path(TreeNode<int> * root, int x, vector<int> ans) {
    if(!root) {
        return;
    }
    
    if(root->data == x) {
        
        ans.push_back(x);
        res = ans;
        return;
    }
    
    ans.push_back(root->data);
    path(root->left, x, ans);
    path(root->right, x, ans);
//     ans.pop_back();
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
   vector<int> ans;
    path(root, x, ans);
    return res;
    
}
