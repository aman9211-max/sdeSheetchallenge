
void Sort(stack<int> &s, int num) {
    if(s.empty() || s.top() < num) {
        s.push(num);
        return;
    }
    int t = s.top();
    s.pop();
    Sort(s, num);
    s.push(t);
}

void sortStack(stack<int> &s)
{
	// Write your code here
    if(s.empty()) {
        return;
    }
    int t  = s.top();
    s.pop();
    sortStack(s);
    
    Sort(s, t);
    
    
}