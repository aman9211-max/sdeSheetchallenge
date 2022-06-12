
#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            q.push(a[i] + b[j]);
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int t = q.top();
        q.pop();
        ans.push_back(t);
        if(ans.size() == k) {
            return ans;
        }
        
    }
    return ans;
    
}