/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<stack>
int findCelebrity(int n) {
 	// Write your code here.
    stack<int> st;
    
    st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() and knows(st.top(), i)) {
            st.pop();
        }
        if(st.empty()) {
            st.push(i);
        }
        else {
            if(!knows(i, st.top()))
                st.push(i);
        }
    }
    
    if(st.empty()) {
        return -1;
    }
    int ans = st.top();
    for(int i = 0; i < n; i++) {
        if(i == ans) {
            continue;
        }
        if(knows(ans, i) || !knows(i, ans)) {
            return -1;
        }
    }
    return ans;
}