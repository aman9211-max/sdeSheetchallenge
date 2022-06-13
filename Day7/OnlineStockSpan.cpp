

#include<stack>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    stack<int> st;
    vector<int> ans(n, 1);
    st.push(0);
    
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(i);
        }
        else {
            while(!st.empty() and price[st.top()] <= price[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = (i - st.top());
            }
            else {
                ans[i] = (i + 1);
            }
            st.push(i);
        }
    }
    return ans;
}