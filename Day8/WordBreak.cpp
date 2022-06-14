#include<bits/stdc++.h>
map<string, bool> m;

bool Break(string s) {
    if(s.empty()) {
        return true;
    }
    if(m.count(s)) {
        return m[s];
    }
    
    for(int i = 1; i <= s.size(); i++) {
        if(m[s.substr(0, i)]) {
            if(Break(s.substr(i))) {
                return m[s] = true;
            }
        }
    }
    return m[s] = false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {        
    for(auto i : arr) {
        m[i] = true;
    }
    bool ans =  Break(target);
    m.clear();
    return ans;
}