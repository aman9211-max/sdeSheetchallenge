#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool ok = true;
void ispallindrome(LinkedListNode<int> *&head, LinkedListNode<int> *temp) {
    if(!temp) return;
    ispallindrome(head, temp->next);
    if(head->data != temp->data) {
        ok = false;
    }
    head = head->next;
    
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    ispallindrome(head, head);
    bool ans = ok;
    ok = true;
    return ans;
}