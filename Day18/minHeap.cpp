
class minheap {
    
    void heapify(int i) {
        int min_index = i;
        int left = 2 * min_index;
        int right = left + 1;
        if(left < v.size() and v[min_index] > v[left]) {
            min_index = left;
        }
        if(right < v.size() and v[min_index] > v[right]) {
            min_index = right;
        }
        if(min_index != i) {
            swap(v[min_index], v[i]);
            heapify(min_index);
        }
    }
    public:
    vector<int> v;
    minheap() {
        v.push_back(-1);
    }
    void push(int data) {
        v.push_back(data);
        int c = v.size() - 1;
        int p = c / 2;
        while(c > 1 and v[p] > v[c]) {
            swap(v[p], v[c]);
            c = p;
            p = p / 2;
        }
    }
    
    int top() {
        return v[1];
    }
    void pop() {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
    
    bool empty() {
        return v.size() == 1;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    minheap h;
    vector<int> ans;
    for(auto i : q) {
        if(i[0] == 0) {
              h.push(i[1]);
        }
        else {
            ans.push_back(h.top());
            h.pop();
        }
    }
    return ans;
}
