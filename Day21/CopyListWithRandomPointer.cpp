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


#define node LinkedListNode<int>

node * dfs(node * head) {
    if(!head) {
        return nullptr;
    }
    node * t = head->next;
    t->next = dfs(head->next->next);
    return t;
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *itr=head;

 

       while(itr!=NULL)

       {  

           LinkedListNode<int> *front=itr->next;

           LinkedListNode<int> *dumy=new LinkedListNode<int> (itr->data);

       dumy->next=itr->next;

        itr->next=dumy;

        itr=front;

       }
    itr = head;
    
   
    while(itr and itr->next) {
        
        
        itr->next->random = itr->random;
        itr = itr->next-> next;
    }
    node *h, *t;
    h = t = nullptr;
    itr = head;
    while(itr) {
        node * front = itr->next->next;
        if(!h) {
            h =  t = itr->next;
            
        }
        else {
            t->next = itr->next;
            t = t->next;
        }
        itr->next = front;
        itr = front;
    }
    return h;
   
   
}
