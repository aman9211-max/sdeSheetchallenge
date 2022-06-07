#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    
    vector<vector<long long int> > ans;
    ans.push_back({1LL});
    if(n == 1) {
        return ans;
    }
    for(int i = 1; i < n; i++) {
        vector<long long int> t = ans.back();
        
        for(int i = t.size() - 2; i >= 0; i--) {
            t[i + 1] = t[i + 1] + t[i];
        }
        t.push_back(1LL);
        ans.push_back(t);
    }
    return ans;
}
