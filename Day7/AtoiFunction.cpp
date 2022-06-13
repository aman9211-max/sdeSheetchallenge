int atoi(string str) {
    // Write your code here.
    int ans = 0;
    for(auto i : str) {
        if(isdigit(i)) {
            ans = ans * 10  + (i - '0');
        }
    }
    if(str[0] == '-') {
        return -ans;
    }
    return ans;
    
}