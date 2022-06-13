/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void bottomView(BinaryTreeNode<int> * root, int level, int d, map<int, pair<int, int> > &m) {
    if(!root) {
        return;
    }
    
    if(m.count(d) == 0 || level >= m[d].second) {
        m[d] = {root->data, level};
    }
    
    bottomView(root->left, level + 1, d - 1, m);
    bottomView(root->right, level + 1, d + 1, m);
    
}
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int, pair<int, int> > m;
    bottomView(root, 0, 0, m);
    vector<int> ans;
    for(auto i : m) {
        ans.push_back(i.second.first);
    }
    return ans;
    
}
