#include<bits/stdc++.h>
int dp[105];
int find(vector<int> &price, int n) {
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, price[i - 1] + find(price, n - i));
    }
    return dp[n] =  ans;
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    memset(dp, -1, sizeof dp);
    return find(price, n);
}
