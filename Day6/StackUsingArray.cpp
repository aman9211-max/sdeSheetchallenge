// Stack class.
class Stack {
    vector<int> v;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        v.push_back(num);
    }

    int pop() {
        // Write your code here.
        if(v.empty()) {
            return -1;
        }
        int t = v.back();
        v.pop_back();
        return t;
    }
    
    int top() {
        // Write your code here.
        if(v.empty()) {
            return -1;
        }
        return v.back();
    }
    
    int isEmpty() {
        // Write your code here.
        return v.empty();
    }
    
    int isFull() {
        // Write your code here.
        return v.size() == size;
    }
    
};