/************************************************************

    Following is the TreeNode class structure:

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
#include<bits/stdc++.h>
void topView(TreeNode<int> * root, int level, int d, map<int, pair<int, int> > &m) {
    if(!root) {
        return;
    }
    
    if(m.count(d) == 0 || level < m[d].second) {
        m[d] = {root->val, level};
    }
    
    topView(root->left, level + 1, d - 1, m);
    topView(root->right, level + 1, d + 1, m);
    
}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int, pair<int, int> > m;
    topView(root, 0, 0, m);
    vector<int> ans;
    for(auto i : m) {
        ans.push_back(i.second.first);
    }
    return ans;
}