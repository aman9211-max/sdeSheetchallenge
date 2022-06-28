#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
LinkedListNode<int> * dfs(LinkedListNode<int> *head, map<LinkedListNode<int> *, LinkedListNode<int> *> &m) {
    if(!head) {
        return nullptr;
    }
    LinkedListNode<int> * t = m[head];
    t->next = dfs(head->next, m);
    t->random = m[head->random];
    return t;
    
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    map<LinkedListNode<int> *, LinkedListNode<int> *> m;
    LinkedListNode<int> * h = head;
    
    while(h) {
        LinkedListNode<int> * x = new LinkedListNode<int>(h->data);
        m[h] = x;
        h = h->next;
    }
    return dfs(head, m);
}

