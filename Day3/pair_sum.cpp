#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    
    vector<vector<int> > ans;
    map<int, vector<int> > m;
    for(int i = 0 ; i < arr.size(); i++) {
        m[arr[i]].push_back(i);
    }
    for(auto i : arr) {
        int t = m[i].back();
        m[i].pop_back();
        int find = s -  i;
        
        for(int j = 0; j < m[find].size(); j++) {
            ans.push_back({min(i, find), max(i, find)});
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}