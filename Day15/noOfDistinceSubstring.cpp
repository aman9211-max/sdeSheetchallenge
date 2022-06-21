
#include<bits/stdc++.h>

int distinctSubstring(string &word) {
    int ans = 0;
    map<string, bool> vis;
    for(int i = 0; i < word.size(); i++) 
    {
       string t;
        for(int j = i; j < word.size(); j++) {
            t.push_back(word[j]);
            if(!vis[t]) {
                ans++;
                vis[t] = true;
            }
        }
       
    }
    return ans;
    
}
