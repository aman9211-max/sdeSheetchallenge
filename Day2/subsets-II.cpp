#include<bits/stdc++.h>

set<vector<int> >  ans;
map<int, bool> vis;
void dfs(vector<int> &arr, int i, int n, vector<int> &res) {
    if(i == n) {
        if(res.size() > 0)
            ans.insert(res);
        return;
    }
    res.push_back(arr[i]);
    dfs(arr, i + 1, n, res);
    res.pop_back();
    dfs(arr, i + 1, n, res);
 }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> res;
    dfs(arr, 0, n, res);
    
    cout << endl;
    
    vector<vector<int> > t;
    for(auto i : ans) t.push_back(i);
    ans.clear();
    return t;
    
}