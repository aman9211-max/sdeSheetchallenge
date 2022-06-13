#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  vector<int> ans(n, -1);
    stack<int> st;
    st.push(0);
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(i);
        }
        else {
            
            while(!st.empty() and arr[st.top()] > arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}