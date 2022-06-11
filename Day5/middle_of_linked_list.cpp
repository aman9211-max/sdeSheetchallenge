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
int len(Node * head) {
    int l = 0;
    while(head) {
        head = head->next;
        l++;
    }
    return l;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int l = len(head);
    l = l / 2;
    while(head and l) {
        l--;
        head = head->next;
    }
    return head;
}