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

int len(Node* head) {
    int l = 0;
    
    while(head) {
        head = head->next;
        l++;
    }
    return l;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here
    if(len(head1) < len(head2)) {
        swap(head1, head2);
    }
    Node * s = head1;
    Node * t = head2;
    Node* prev = nullptr;
    int carry = 0;
    while(s and t) {
        int l = s->data + t->data + carry;
        s->data = (l) % 10;
        carry = (l) / 10;
        prev = s;
        s = s->next;
        t = t->next;
    }
    
    if(carry)
    {
        if(s) {
            while(s and carry > 0) {
                int l = s->data + carry;
                s->data = (l) % 10;
                carry = (l) / 10;
                prev = s;
                s = s->next;
            }
        }
    }    
    
    if(carry) {
        prev->next = new Node(carry);
    }
    return head1;
}