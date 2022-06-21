
#include<bits/stdc++.h>
class node {
    public:
    char ch;
    int cnt;
    bool isTerminal;
    unordered_map<int, node*> h;
    node(char ch) {
        ch = '\0';
        isTerminal = false;
        cnt = 0;
    }
};

class Trie{
node * root;
    public:

    Trie(){
        // Write your code here.
        root = new node('\0');
    }

    void insert(string &word){
        // Write your code here.
        
        node * temp = root;
        for(auto &i : word) {
            if(temp->h.count(i) == 0) {
                temp->h[i] = new node(i);
            }
            temp = temp->h[i];
            temp->cnt++;
        }
        temp->isTerminal = true;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        
        node * temp = root;
        
        for(auto &i : word) {
            if(!temp->h.count(i)) {
                return 0;
            }
            temp = temp->h[i];
        }
        if(temp->isTerminal) {
            return temp->cnt;
        }
        return 0;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        
         
        node * temp = root;
        
        for(auto &i : word) {
            if(temp->h.count(i) == 0) {
                return 0;
            }
            temp = temp->h[i];
        }
            return temp->cnt;
    }

    void erase(string &word){
        // Write your code here.
       node * temp = root;
        
        for(auto &i : word) {
            node * curr = temp->h[i];
            curr->cnt--;
            if(curr->cnt == 0) {
                temp->h[i] = nullptr;
            }
            temp = curr;
        }
        temp->cnt--;
        if(temp->cnt == 0) {
            temp->isTerminal = false;
        }
    }
};
