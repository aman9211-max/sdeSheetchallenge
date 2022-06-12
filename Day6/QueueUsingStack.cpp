#include<bits/stdc++.h>

class Queue {
    // Define the data members(if any) here.
    stack<int> s1, s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
        
    }

    int deQueue() {
        // Implement the dequeue() function.
         if(s1.size() == 0) {
            return -1;
        }
        
        while(s1.size() > 1) {
            int t = s1.top();
            s1.pop();
            s2.push(t);
        }
        int ans = s1.top();
        s1.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek() {
        // Implement the peek() function here.
         if(s1.size() == 0) {
            return -1;
        }
        
        while(s1.size() > 1) {
            int t = s1.top();
            s1.pop();
            s2.push(t);
        }
        int ans = s1.top();
        s2.push(s1.top());
        s1.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
       
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.size() == 0;
    }
};