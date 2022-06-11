#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int> *sort(Node<int> *f, Node<int> *r) {
    if(!f) {
        return r;
    }
    if(!r) {
        return f;
        
    }
    Node<int> * ans;
    if(f->data < r->data) {
        ans = f;
        ans->next = sort(f->next, r);
        return ans;
    }
    ans = r;
    ans->next = sort(f, r->next);
    return ans;
    
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    return sort(first, second);
}
