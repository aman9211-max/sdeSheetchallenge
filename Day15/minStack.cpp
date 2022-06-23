// Implement class for minStack.
#include<bits/stdc++.h>
class minStack
{
	// Write your code here.
	vector<int> v;
    multiset<int> st;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            v.push_back(num);
            st.insert(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(v.empty()) 
            {
                return -1;
            }
			// Write your code here.
            int t = v.back();
            v.pop_back();
            st.erase(st.lower_bound(t));
            return t;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(v.empty()) return -1;
            return v.back();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(st.empty()) {
                return -1;
            }
            return *st.begin();
		}
};