#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/

Node *rotate(Node *head, int k) {
    if(k == 0 || !head || !head->next) {
        return head;
    }
    int len = 1;
    Node * curr = head;
    
    while(curr->next) {
        len++;
        curr = curr->next;
    }
    curr->next = head;
    k %= len;
    k = len - k;
    while(k--) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;
    return head;
    
}