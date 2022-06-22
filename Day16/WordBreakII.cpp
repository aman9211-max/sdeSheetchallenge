#include<bits/stdc++.h>
map<string, bool> vis;
void solve(string s, vector<string> &d, string res, vector<string> &ans) {
    if(s.empty()) {
        if(res.size() > 0 and !vis[res.substr(1)]) {
            ans.push_back(res.substr(1));
            vis[res.substr(1)] = true;
        }
        return;
    }
    for(auto i : d) {
        int size = i.size();
        if(s.size() >= size and s.substr(0, size) == i) {
            solve(s.substr(size), d, res + " " + i, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    solve(s, dictionary, "", ans);
    vis.clear();
    return ans;
}