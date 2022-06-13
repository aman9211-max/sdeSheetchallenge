#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> ans(n, -1);
    st.push(0);
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(i);
        }
        else {
            
            while(!st.empty() and arr[st.top()] < arr[i]) {
               ans[st.top()] = arr[i];
                st.pop();
            }
//             if(!st.empty()) {
//                 ans[st.top()] = arr[i];
//             }
            st.push(i);
        }
    }
    return ans;
}