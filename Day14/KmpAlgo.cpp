
bool findPattern(string p, string s)
{
    // Write your code here.
    int n = s.size();
    int m = p.size();
    vector<int> lps(m, 0);
   { int i = 0;
    int j = 1;
    
    while(j < m) {
        if(p[i] == p[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else {
            if(i != 0) {
                i = lps[i - 1];
            }
            else {
                lps[j] = 0;
                j++;
            }
        }
    }}
    int i = 0;
    int j = 0;
    
    while(i < s.size() and j < p.size()) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        if(j >= m) {
            return true;
        }
        else if(i < n and s[i] != p[j]) {
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i = i + 1;
            }
        }
    }
    return false;
    
}