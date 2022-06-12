
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> m;
    for(auto i : arr) {
        m[i]++;
    }
    priority_queue<pair<int, int> > q;
    
    for(auto i : m) {
        q.push({i.second, i.first});
    }
    
    vector<int> ans;
    while(k--) {
        ans.push_back(q.top().second);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}