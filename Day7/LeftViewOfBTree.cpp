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
void leftView(TreeNode<int> *root, int level, int &max_level, vector<int> &ans) {
    if(!root) {
        return;
        
    }
    if(level > max_level) {
        ans.push_back(root->data);
        max_level = level;
    }
    leftView(root->left, level + 1, max_level, ans);
    leftView(root->right, level + 1, max_level, ans);

}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    int max_level = -1;
    leftView(root, 0, max_level, ans);
    return ans;
}