#include<bits/stdc++.h>
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
bool comp(vector<int> &a, vector<int> &b) {
    return (a[1] < b[1]);
}


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    sort(arr.begin(), arr.end());
    vector<int> ans(queries.size(), 0);
    for(int i = 0; i < queries.size(); i++) {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), comp);
    
    Trie t;
    int j = 0;
    for(auto i : queries) {
        while(j < arr.size() and arr[j] <= i[1]) {
            t.insert(arr[j]);
            j++;
        }
        if(j == 0) {
            ans[i[2]] = -1;
            continue;
        }
        ans[i[2]] = t.max_xor(i[0]);
    }
    return ans;
    
}