#include<bits/stdc++.h>

int dp[1005][1005];
int knapsack(vector<int> &value, vector<int> &weight, int i, int n, int w) {
      if(w < 0) {
          return 0;
      }
    if(i == n) {
        return 0;
    }
    if(dp[i][w] != -1) {
        return dp[i][w];
    }
    int op1, op2;
    op1 = op2 = 0;
    if(w - weight[i] >= 0) {
        op1 = value[i] + knapsack(value, weight, i + 1, n, w - weight[i]);
    }
    op2 = knapsack(value, weight, i + 1, n, w);
    return dp[i][w] = max(op1, op2);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    
    memset(dp, -1, sizeof dp);
    return knapsack(values, weights, 0, n, w);
}