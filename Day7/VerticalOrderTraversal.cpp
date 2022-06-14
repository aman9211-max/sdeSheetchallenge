/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

#include<map>
void VerticalOrder(TreeNode<int> *root, int level, int d, map<int, vector<pair<int, int> > > &m) {
    if(!root) {
        return;
    }
//     if(m[d].empty() || (m[d].back()).second <= level) {
        m[d].push_back({level, root->data});
//     }
    
    VerticalOrder(root->left, level + 1, d - 1, m);
    VerticalOrder(root->right, level + 1, d + 1, m);
}



vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int, vector<pair<int, int> > > m;
    VerticalOrder(root, 0, 0, m);
    vector<int> ans;
    for(auto i : m) {
        sort(m[i.first].begin(), m[i.first].end());
        for(auto j : i.second) {
            ans.push_back(j.second);
        }
    }
    return ans;
}