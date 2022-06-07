#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int prefix[n];
    prefix[0] = prices[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = min(prefix[i - 1], prices[i]);
    }
    
    int suffix[n];
    suffix[n - 1] = prices[n - 1];
    for(int i =  n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], prices[i]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans = max(ans, suffix[i + 1] - prefix[i]);
    }
    return ans;
    
}