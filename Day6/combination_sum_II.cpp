#include<bits/stdc++.h>

void dfs(vector<int> &arr, int i, int sum , int target, vector<int> &res, vector<vector<int> > &ans) {
      if(target == sum) {
          ans.push_back(res);
          return;
      }
    for(int j = i; j < arr.size(); j++) {
        if(j > i and arr[j] == arr[j - 1]) {
            continue;
        }
        res.push_back(arr[j]);
        dfs(arr, j + 1, sum + arr[j], target, res, ans);
        res.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int> > ans;
    sort(arr.begin(), arr.end());
    vector<int> res;
    dfs(arr, 0, 0, target, res, ans);
    return ans;
}
