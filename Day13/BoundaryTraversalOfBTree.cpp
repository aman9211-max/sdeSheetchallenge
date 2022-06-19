
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void left_fill(TreeNode<int> * root, TreeNode<int> * root1, vector<int> &ans) {
    if(!root) {
        return;
    }
    if(!root->left and !root->right) {
        return;
    }
    else if(!root->left and root != root1) {
        ans.push_back(root->data);
        left_fill(root->right, root1, ans);
        return;
    }
    ans.push_back(root->data);
    left_fill(root->left,root1, ans);
    
}

void leaf_fill(TreeNode<int> * root, vector<int> &ans) {
    if(!root) {
        return;
    }
    if(!root->left and !root->right) {
        ans.push_back(root->data);
        return;
    }
    
    leaf_fill(root->left, ans);
    leaf_fill(root->right, ans);
}
void right_fill(TreeNode<int> * root, TreeNode<int> * root1, vector<int> &ans) {
    if(!root) {
        return;
    }
    if(!root->left and !root->right) {
        return;
    }
    else if(!root->right and root != root1) {
        right_fill(root->left, root1, ans);
    }
    
    right_fill(root->right,root1, ans);
    ans.push_back(root->data);
    
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    left_fill(root, root, ans);
    leaf_fill(root, ans);
    right_fill(root->right, root, ans);
    return ans;
    
}