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

class BSTiterator
{
    int it = 0;
    vector<int> node;
    public:
    void fill(TreeNode<int> *root) {
        if(!root) return;
        fill(root->left);
        node.push_back(root->data);
        fill(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        fill(root);
    }

    int next()
    {
        // write your code here
        return node[it++];
        
    }

    bool hasNext()
    {
        // write your code here
        if(it < node.size()) return true;
        return false;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/