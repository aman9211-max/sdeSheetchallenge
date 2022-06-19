
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, INT_MAX / 2));
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    
    for(auto i : edges) {
        dp[i[0]][i[1]] = i[2];
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    return min((int) 1e9, dp[src][dest]);
}