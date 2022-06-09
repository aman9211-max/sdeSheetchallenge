
vector<string> ans;
void permutation(string &s, int  i) {
    if(i == s.size()) {
        ans.push_back(s);
        return;
    }
    for(int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permutation(s, i + 1);
        swap(s[i], s[j]);
    }
 }

vector<string> findPermutations(string &s) {
    // Write your code here.
    permutation(s, 0);
    vector<string> res = ans;
    ans.clear();
    return res;
}