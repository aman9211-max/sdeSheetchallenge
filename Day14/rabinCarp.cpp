
int hash1(string t) {
    int m = t.size();
    int ans = 0;
    for(int i = 0; i < t.size(); i++) {
        ans += (m - i) * (t[i] - 'A' + 1);
    }
    return ans;
}



vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int m = pat.size();
    int i = 0;
    int j = m - 1;
    int n = str.size();
    vector<int> prefix(n, 0);
    prefix[0] = (str[0] - 'A' + 1);
    for(int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1] + (str[i] - 'A' + 1);
    }
    vector<int> ans;
    int x = hash1(str.substr(0, m));
    int h = hash1(pat);
    if(x == h and str.substr(0, m) == pat) {
        ans.push_back(i);
    }
    while(j < n) {
         x -= (m * (str[i] - 'A' + 1));
        i++;
        x += (prefix[j] - prefix[i - 1]);
        
        j++;
        if(j < n) {
            
            x += (str[j] - 'A' + 1);
            
        }
        if(x == h and pat == str.substr(i, m)) {
            ans.push_back(i);
        }
    }
    return ans;
    
}
