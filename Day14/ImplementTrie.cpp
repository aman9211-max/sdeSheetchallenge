
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
#include<bits/stdc++.h>
class node {
    public:
    char ch;
    bool isTerminal;
    unordered_map<char, node*> h;
    
    node(char ch) {
        ch = '\0';
        isTerminal = false;
    }
};


class Trie {
    node * root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new node('\0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node * temp = root;
        for(auto i : word) {
            if(temp->h.count(i)) {
                temp = temp->h[i];
            }
            else {
                temp->h[i] = new node(i);
                temp = temp->h[i];
            }
        }
        temp->isTerminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node * temp = root;
        for(auto i : word) {
            char ch = i;
            if(temp->h.count(ch)) 
            {
                temp = temp->h[ch];
            }
            else {
                return false;
            }
        }
        return temp->isTerminal;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node * temp = root;
        for(auto i : prefix) {
            char ch = i;
            if(temp->h.count(ch)) 
            {
                temp = temp->h[ch];
            }
            else {
                return false;
            }
        }
        return true;
        
    }
};