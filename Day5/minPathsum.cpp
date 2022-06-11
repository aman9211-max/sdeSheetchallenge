#include<bits/stdc++.h>
int dp[105][105];
int minPath(vector<vector<int> > &grid, int i, int j) {
    if(i == grid.size() - 1 and j == grid[0].size() - 1) {
        return grid[i][j];
    }
    if(i >= grid.size() || j >= grid[0].size()) {
        return INT_MAX / 2;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    return dp[i][j] = grid[i][j] + min(minPath(grid, i + 1, j), minPath(grid, i, j + 1));
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    memset(dp, -1, sizeof dp);
    return minPath(grid, 0, 0);
}