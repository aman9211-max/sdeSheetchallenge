#include<bits/stdc++.h>
unordered_map<int, vector<int> > adj;
bool cycle_directed_dfs_helper(int node, unordered_map<int, bool> &vis, unordered_map<int, bool> &inStack) {
        vis[node] = true;
        inStack[node] = true;
        for (auto neighbours    : adj[node]) {
            if (!vis[neighbours] and cycle_directed_dfs_helper(neighbours, vis, inStack) || inStack[neighbours]) {

                return true;

            }
        }

        inStack[node] = false;
        return false;
    }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    for(auto i : edges) {
        adj[i.first].push_back(i.second);
    }
    unordered_map<int, bool> vis;

        unordered_map<int, bool> inStack;

        for (auto p : adj)  {
            int node = p.first;

            if (!vis[node]) {
                bool kyacycleh = cycle_directed_dfs_helper(node, vis, inStack);
                if (kyacycleh) {
                    adj.clear();
                    return true;
                }
            }
        }

        adj.clear();
        return false;
    
}