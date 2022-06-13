
#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    int ans = 0;
    
    while(!q.empty()) {
        int size = q.size();
        bool ok = false;
        while(size--) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
//             grid[x][y] = 2;
            if(x + 1 < n and grid[x + 1][y] == 1) {
                ok = true;
                grid[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if(x - 1 >= 0 and grid[x - 1][y] == 1) {
                ok = true;
                grid[x - 1][y] = 2;
                q.push({x - 1, y});
            }
            if(y + 1 < m and grid[x][y + 1] == 1) {
                ok = true;
                grid[x][y + 1] = 2;
                q.push({x, y + 1});
            }
            if(y - 1 >= 0 and grid[x][y - 1] == 1) {
                ok = true;
                grid[x][y  - 1] = 2;
                q.push({x, y - 1});
            }
        }
        if(ok)
            ans++;
        else break;
    }
    
    for(auto i : grid) {
        for(auto j : i) {
            if(j == 1) {
                return -1;
            }
        }
    }
    return ans;
}