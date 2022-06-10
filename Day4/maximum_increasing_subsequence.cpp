int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
    
    
    int dp[n + 1];
    int ans =rack[0];
    dp[0] = rack[0];
    
    for(int i = 1; i < n; i++) {
        dp[i] = rack[i];
        for(int j = 0; j < i; j++) {
            if(rack[j] < rack[i]) {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
    
    
}