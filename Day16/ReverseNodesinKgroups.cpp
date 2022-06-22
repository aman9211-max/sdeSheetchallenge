#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/
Node * getReverse(Node * head, int *b, int i, int n) {
    if(!head) {
        return nullptr;
    }
   
    if(i == n) {
        return head;
    }
    if(b[i] == 0) {
        return getReverse(head, b,  i + 1, n);
    }
     Node * prev = nullptr;
        Node * curr = head;
        Node * next = curr;
        int l = 1;
        while(curr and l <= b[i]) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            l++;
        }
    head->next = curr;
    head->next = getReverse(curr, b, i + 1, n);
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    
    
    return getReverse(head, b, 0, n);
}