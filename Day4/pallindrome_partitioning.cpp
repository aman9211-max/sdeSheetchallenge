



bool ispallindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

void find(string s, vector<string> &res, vector<vector<string>  > &ans) {
    if(s.empty()) {
//         sort(res.begin(), res.end());
        ans.push_back(res);
        return;
    }
    
    for(int i = 0; i < s.size(); i++) {
        if(ispallindrome(s.substr(0, i + 1))) {
            res.push_back(s.substr(0, i + 1));
            find(s.substr(i + 1), res, ans);
            res.pop_back();
        }
    }
    return;
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string> > ans;
    vector<string> res;
    find(s, res, ans);
   
    
    return ans;
    
    
}