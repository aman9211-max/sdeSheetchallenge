#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    if(!root) {
        return 0;
    }
    int ans = 1;
    queue<TreeNode<int> * > q;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        ans = max(ans, n);
        for(int i = 0; i < n; i++) {
            auto it = q.front();
            q.pop();
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
    }
    return ans;
}