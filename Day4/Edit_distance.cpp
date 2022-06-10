#include<bits/stdc++.h>


int dp[1005][1005];


int steps(string &s, string &t, int i, int j) {
    if(i == s.size() and j == t.size()) {
        return 0;
    }
    if(j == t.size()) {
        return dp[i][j] = 1 + steps(s, t, i + 1, j);
    }
    if(i == s.size()) {
        return dp[i][j] = 1 + steps(s, t, i, j + 1);
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(s[i] == t[j]) {
        return dp[i][j] = steps(s, t, i + 1, j + 1);
    }
    
    int op1 = 1 + steps(s, t, i + 1, j);
    int op2 = 1 + steps(s, t, i + 1, j + 1);
    int op3 = 1 + steps(s, t, i, j + 1);
    return dp[i][j] = min({op1, op2, op3});
    
}
int editDistance(string str1, string str2)
{
    memset(dp, -1, sizeof dp);
    return steps(str1, str2, 0, 0);
    
}