#include<bits/stdc++.h>
class Kthlargest {
    priority_queue<int, vector<int>, greater<int> > q;
    int size;
public:
    Kthlargest(int k, vector<int> &arr) {
       for(auto i : arr) {
           q.push(i);
       }
       size = k;
    }

    void add(int num) {
       q.push(num);
    }

    int getKthLargest() {
       while(q.size() > size) {
           q.pop();
       }
        return q.top();
    }

};