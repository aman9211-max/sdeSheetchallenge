#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int, int> m;
    int ans = 1;
    for(auto i : arr) {
        m[i]++;
    }
    
    for(auto i : arr) {
        if(m.find(i - 1) == m.end()) {
            
            int cnt = 1;
            int t = i;
            while(m.find(t + 1) != m.end()) {
                t++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
    
}