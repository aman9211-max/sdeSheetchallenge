
class node {
    public:
    int val;
    node * left, *right;
    node() {
        left = right = nullptr;
    }
};

class Trie {
    node * root;
    public:
    Trie() {
        root = new node();
    }
    
    void insert(int d) {
        node * temp = root;
        for(int i = 31; i >= 0; i--) {
            if((d >> i) & 1) {
                if(temp->right) {
                    temp = temp->right;
                }
                else 
                {
                    temp->right = new node();
                    temp = temp->right;
                }
            }
            else {
                if(temp->left) {
                    temp = temp->left;
                }
                else {
                    temp->left = new node();
                    temp = temp->left;
                }
                
            }
        }
        
        temp->val = d;
    }
    
    int max_xor(int d) {
        node * temp = root;
        int result = 0;
        for(int i  = 31; i >= 0; i--) {
            if((d >> i)  & 1) {
                if(temp->left) {
                    result += (1 << i);
                    temp = temp->left;
                    
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                if(temp->right) {
                    result += (1 << i);
                    temp = temp->right;
                    
                }
                else {
                    temp = temp->left;
                }
            }
        }
        return result;    
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.  
    Trie t;
    int ans = 0;
    for(auto i : A) {
        t.insert(i);
        ans = max(ans, t.max_xor(i));
    }
    return ans;
    
}