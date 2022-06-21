
void solve(vector<int> &v, int i, vector<int> &res, vector<vector<int> > &ans) {
    if(i == v.size()) {
        ans.push_back(res);
        return;
    }
    res.push_back(v[i]);
    solve(v, i + 1, res, ans);
    res.pop_back();
    solve(v, i + 1, res, ans);
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int> > ans;
    vector<int> res;
    solve(v, 0, res, ans);
    return ans;
    
}