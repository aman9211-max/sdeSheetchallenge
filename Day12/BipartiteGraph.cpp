#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    map<int, vector<int> > m;
    int n = edges.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(edges[i][j] == 1) {
                m[i].push_back(j);
                m[j].push_back(i);
            }
        }
    }
    vector<int> color(n, 0);
    for(int i = 0; i < n; i++) {
        if(color[i] == 0) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    int node = q.front();
                    q.pop();
                    for(auto k : m[node]) {
                        if(color[k] == 0) {
                            color[k] = -color[node];
                            q.push(k);
                        }
                        else {
                            if(color[node] == color[k]) {
                                return false;
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return true;
}