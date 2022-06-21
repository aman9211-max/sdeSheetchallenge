 #include<bits/stdc++.h>

int largestRectangle(vector < int > & heights) {
   // Write your code here.
     stack<int> st;
     int i = 0;
     int ans = 0;
     while(i < heights.size()) {
         if(st.empty() || heights[st.top()] <= heights[i]) {
             st.push(i++);
         }
         else {
             int t = st.top();
             st.pop();
             int  a = heights[t] * (st.empty() ? i : (i - st.top() - 1));
             ans = max(ans, a);
         }
     }
     
     while(!st.empty()) {
         int t = st.top();
         st.pop();
         int a = heights[t] * (st.empty() ? i : (i - st.top() - 1));
         ans = max(ans, a);
     }
     return ans;
     
     
 }