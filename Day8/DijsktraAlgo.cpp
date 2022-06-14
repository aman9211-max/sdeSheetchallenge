#include<bits/stdc++.h>


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    map<int, vector<pair<int, int> > > g;
    for(auto i : vec) {
        g[i[0]].push_back({i[1], i[2]});
        g[i[1]].push_back({i[0], i[2]});
    }
    map<int, int> distance;
    for(auto i : g) {
       distance[i.first] = INT_MAX;
    }
    map<int, int> p;
    distance[source] = 0;
    p[source] = source;
    set<pair<int, int> > s;
    s.insert({0, source});
    while(!s.empty()) {
        auto node = *(s.begin());
        s.erase(s.begin());
        int parent_dist = node.first;
        int parent = node.second;
        for(auto child : g[parent]) {
            int edge_dist = child.second;
            if(distance[child.first] > parent_dist + edge_dist) {
                auto f = s.find({distance[child.first], child.first});
                if(f != s.end()) {
                    s.erase(f);
                }
                
                p[child.first] = parent;
                distance[child.first] = parent_dist + edge_dist;
                s.insert({distance[child.first], child.first});
            }
        }
    }
    vector<int> v;
    for(int i = 0; i < vertices; i++) {
        v.push_back(distance[i]);
    }
    return v;
    
    
    
}
