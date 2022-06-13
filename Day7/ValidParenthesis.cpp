bool isValidParenthesis(string e)
{
    // Write your code here.
    
    
    stack<char> st;
    for(auto i : e) {
        if(i == '(' || i == '{' || i == '[') {
            st.push(i);
        }
        else if(i == ')') {
            if(!st.empty() and st.top() == '(') {
                st.pop();
            }
            else {
                return false;
            }
        }
        else if(i == '}') {
            if(!st.empty() and st.top() == '{') {
                st.pop();
            }
            else {
                return false;
            }
        }
        else if(i == ']') {
            if(!st.empty() and st.top() == '[') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}