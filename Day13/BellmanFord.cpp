
#include<bits/stdc++.h>

int bellmonFord(int n, int mp, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    map<int, vector<pair<int, int>> > m;
       for(auto i : edges) {
           m[i[0]].push_back({i[1], i[2]});
       }
    map<int, int> dist;
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int i = 1; i < n; i++) {
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                for(auto j : m[node]) {
                    if(dist[j.first] > dist[node] + j.second) 
                    {
                        dist[j.first] = dist[node] + j.second;
                    }
                    q.push(j.first);
                }
            }
        }
    }
    return min((int) 1e9, dist[dest]);
    
}