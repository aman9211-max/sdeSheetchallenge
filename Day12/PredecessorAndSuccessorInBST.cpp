/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inOrder(BinaryTreeNode<int>* root, pair<int,int> &ans,bool &found, int key) {
    if(!root) {
        return;
    }
    inOrder(root->left, ans, found, key);
    if(root->data == key) {
        found = true;
    }
    if(!found) {
        ans.first = root->data;
    }
    else {
        if(ans.second == -1 and root->data != key) {
            ans.second = root->data;
        }
    }
    
    inOrder(root->right, ans, found, key);
    
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int, int> ans = {-1, -1};
    bool found = false;
    inOrder(root, ans, found, key);
    return ans;
    
}
