/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int> * arrToBst(vector<int> &arr, int i, int j) {
    if(i > j) {
        return nullptr;
    }
    int mid = (i + j) / 2;
    TreeNode<int> * n = new TreeNode<int> (arr[mid]);
    n->left = arrToBst(arr, i, mid - 1);
    n->right = arrToBst(arr, mid + 1, j);
    return n;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return arrToBst(arr, 0, n -1);
    // Write your code here.
}