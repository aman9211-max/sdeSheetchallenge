int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    priority_queue<int, vector<int>, greater<int> > q;
    for(auto i : arr) {
        q.push(i);
        if(q.size() > K) q.pop();
    }
    return q.top();
}