
#include<bits/stdc++.h>
class Queue {
public:
    vector<int> v;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return v.size() == 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(v.size() == 0) return -1;
        reverse(v.begin(), v.end());
        int t = v.back();
        v.pop_back();
        reverse(v.begin(), v.end());
        return t;
    }

    int front() {
        // Implement the front() function
        if(v.empty()) return -1;
        return v[0];
    }
};