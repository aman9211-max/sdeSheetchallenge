int lcs(string &s, string &t)
{
	//Write your code here
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i+1][j+1], 1 + dp[i][j]);
            }
             dp[i + 1][j + 1] = max(dp[i+1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
        }
    }
    return dp[n][m];
}