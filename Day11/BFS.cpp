#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    map<int, vector<int> > m;
    for(auto i : edges) {
        m[i.first].push_back(i.second);
        m[i.second].push_back(i.first);
    }
    for(auto i : m) {
        sort(m[i.first].begin(), m[i.first].end());
    }
    map<int, bool> vis;
    queue<int> q;
    
    for(int i = 0; i < vertex; i++) {
       if(vis[i]) continue;
       q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int f = q.front();
                q.pop();
                ans.push_back(f);
                for(auto node : m[f]) {
                    if(!vis[node]) {
                       q.push(node);
                       vis[node] = true;
                    }
                }
            }
        }
    }
    return ans;
}