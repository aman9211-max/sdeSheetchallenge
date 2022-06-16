/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> * createTree(vector<int> &preOrder, int i, int j) {
    if(i > j) {
        return nullptr;
    }
    TreeNode<int> * n = new TreeNode<int> (preOrder[i]);
    int indx = i + 1;
    
    while(indx < preOrder.size() and preOrder[indx] <= preOrder[i]) {
        indx++;
        
    }
    n->left = createTree(preOrder, i + 1, indx - 1);
    n->right = createTree(preOrder, indx, j);
    return n;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here
        return createTree(preOrder, 0, preOrder.size() - 1);
    
}