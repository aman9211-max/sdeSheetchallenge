#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int j = 0; j  < n; j++) {
        int i = arr[j];
        if(j & 1) {
            maxHeap.push(i);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            ans.push_back((maxHeap.top() + minHeap.top()) / 2);
        }
        else {
            minHeap.push(i);
            maxHeap.push(minHeap.top());
            minHeap.pop();
            ans.push_back(maxHeap.top());
        }
    }
    return ans;
    
}
