
#include<bits/stdc++.h>
int Sum(vector<int> &arr) {
    int sum = 0;
    for(auto i : arr) sum += i;
    return sum;
}
void dfs(vector<int> &arr, int i, int n, int k, vector<int> &res, vector<vector<int> > &ans) {
    
    if(i >= n) {
        if(Sum(res) == k) {
            ans.push_back(res);
        }
        return;
    }
    res.push_back(arr[i]);
    dfs(arr, i + 1, n, k, res, ans);
    res.pop_back();
    dfs(arr, i + 1, n, k, res, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int> > ans;
    vector<int> res;
    dfs(arr, 0, n, k, res,  ans);
    return ans;
}