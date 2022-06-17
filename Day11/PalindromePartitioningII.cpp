#include<bits/stdc++.h>

bool ispalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
unordered_map<string, int> dp;
int cuts(string str) {
    if(str.empty()) return 0;
    int op = INT_MAX / 2;
    if(dp.count(str) > 0) {
        return dp[str];
    }
       for(int i = 0; i < str.size(); i++) {
           if(ispalindrome(str.substr(0, i + 1))) {
                 op = min(op, 1 + cuts(str.substr(i + 1))); 
           }
       }
    return dp[str] = op;
}
int palindromePartitioning(string str) {
    // Write your code here
    int ans =  cuts(str) - 1;
       dp.clear();
    return ans;
}
