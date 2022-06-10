
#include<bits/stdc++.h>

long countWaysToMakeChange(int *d, int n, int value)
{
    //Write your code here
    long dp[n + 2][value + 2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(long i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for(long i = 1; i <= value; i++) {
        dp[0][i] = 0;
    }
    for(long j = 1; j <= value; j++) {
        for(long i = 1; i <= n; i++) {
            if(j - d[i - 1] >= 0) {
                dp[i][j] = dp[i][j - d[i - 1]];
            }
            
            dp[i][j] += dp[i - 1][j];
        }
    }
    
    return dp[n][value];
    
    
}