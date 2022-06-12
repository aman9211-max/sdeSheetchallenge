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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(!head) {
        return  nullptr;
    }
    if(K == 0) {
        return head;
    }
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    for(int i = 0; i < K; i++) {
        fast = fast->next;
    }
    if(fast == nullptr) {
        return head->next;
    }
   while(fast->next) {
       fast = fast->next;
       slow = slow->next;
   }
    slow->next= slow->next->next;
    return head;
}