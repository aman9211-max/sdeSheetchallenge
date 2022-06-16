/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool fine(queue<BinaryTreeNode<int>* > q) {
    vector<int> v;
    while(!q.empty()) {
        v.push_back(q.front()->data);
        q.pop();
    }
    int i = 0;
    int j = v.size() - 1;
    
    while(i <= j) {
        if(v[i] != v[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
    
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root){
        return true;
    }
    // Write your code here.
    queue<BinaryTreeNode<int>* > q;
    if(root->left) q.push(root->left);
    if(root->right) q.push(root->right);
    
    while(!q.empty()) {
        int size = q.size();
        if(size & 1) {
            return false;
        }
       if(fine(q)) {
           while(size--) 
           {
               auto it = q.front();
               q.pop();
               if(it->left) q.push(it->left);
               if(it->right) q.push(it->right);
           }
       }
        else {
            return false;
        }
    }
    return true;
    
    
}