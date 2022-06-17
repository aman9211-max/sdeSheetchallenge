
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, int> in_deg;
    unordered_map<int, vector<int> > g;
    
    for(auto i : edges) {
        in_deg[i[1]]++;
        g[i[0]].push_back(i[1]);
    }
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(in_deg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto j : g[t]) {
                in_deg[j]--;
                if(in_deg[j] == 0){
                    q.push(j);
                }
            }
        }
    }
    return ans;
}