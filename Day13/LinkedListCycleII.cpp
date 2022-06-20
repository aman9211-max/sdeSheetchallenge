
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

Node *firstNode(Node *head)
{
	Node *fast, *slow;
    fast = slow = head;
    
    while(fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
          break;
        }
    }
    if(!fast || !fast->next)  {
           return nullptr;
    }
    slow = head;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}