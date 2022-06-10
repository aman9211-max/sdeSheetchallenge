int romanToInt(string s) {
    // Write your code here
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0;
    ans += m[s.back()];
    for(int  i = s.size() - 2; i >= 0; i--) {
        if(m[s[i]] < m[s[i + 1]]) {
            ans -= m[s[i]];
        }
        else
        ans += m[s[i]];
    }
    return ans;
}
