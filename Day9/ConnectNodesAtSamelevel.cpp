/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int> * > q;
    q.push(root);
    while(!q.empty()) {
        
        auto node = q.front();
        q.pop();
        int size = q.size();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        while(size--) {
            auto node1 = q.front();
            q.pop();
            node->next = node1;
            node = node1;
            
            if(node1->left) q.push(node1->left);
            if(node1->right) q.push(node1->right);
        }
        
    }
}