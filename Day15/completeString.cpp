#include<bits/stdc++.h>

class node {
    public:
    char ch;
    bool isTerminal;
    unordered_map<int, node*> h;
    node(char ch) {
        ch = '\0';
        isTerminal = false;
    }
};


class Trie {
    node * root;
    public:
    Trie() {
        root = new node('\0');
    }
    void insert(string &word) {
        node * temp = root;
        for(auto &i :  word) {
            if(temp->h.count(i)) {
                temp =  temp->h[i];
            }
            else {
                temp->h[i] = new node(i);
                temp = temp->h[i];
            }
        }
        
        temp->isTerminal = true;
    }
    
    bool isPresent(string &s) {
        node * temp = root;
        for(auto &i : s) {
            if(temp->h.count(i)) {
                temp = temp->h[i];
                if(temp->isTerminal == false) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    string ans;
    sort(a.begin(), a.end());
    
    for(auto i : a) {
        t.insert(i);
    }
    for(auto i : a) {
        if(t.isPresent(i)) {
            if(ans.size() < i.size()) {
                ans = i;
            }
        }
    }
    if(ans.empty()) {
        return "None";
    }
    return ans;
}