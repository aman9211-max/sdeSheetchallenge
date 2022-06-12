vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < a.size() and j < b.size()) {
        if(a[i] >= b[j]) {
            ans.push_back(b[j]);
            j++;
        }
        else {
            ans.push_back(a[i]);
            i++;
        }
    }
    
    while(i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }
    while(j < b.size()) {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&v, int k)
{
    // Write your code here. 
    int s = 0;
    int e = v.size() - 1;
    
    while(s < e) {
        int l = s;
        int r = e;
        
        while(l < r) {
            v[l] = merge(v[l], v[r]);
            l++;
            r--;
        }
        s = 0;
        e = r;
    }
    
    return v[0];
}
