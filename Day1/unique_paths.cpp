#include <bits/stdc++.h> 
int dp[100][100];
int cnt(int i, int j, int n, int m) {
    
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return 0;
    }
    if(i == n - 1 and j == m - 1) {
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    return dp[i][j] = cnt(i + 1, j, n, m) + cnt(i, j + 1, n, m);
}
int uniquePaths(int m, int n) {
	// Write your code here.
    
    memset(dp, -1, sizeof dp);
    return cnt(0,0,n,m);
}