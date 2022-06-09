
vector<vector<vector<int> > > res;
bool isvalid(vector<vector<int> > &v, int n, int row, int col) {
        int i = row - 1;
        int j = col - 1;
        
        while(i >= 0 and j >= 0) {
            if(v[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }
        i  = row - 1;
        j = col + 1;
        while(i >= 0 and j < n) {
            if(v[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }
        i = row - 1;
        j = col;
        
        while(i >= 0) {
            if(v[i][j] == 1) {
                return false;
            }
            i--;
        }
        return true;
    }
bool nQueen(int n, vector<vector<int> > &ans, int i) {
    if(i == n) 
    {
      return true;
    }    
    for(int j = 0; j  < n; j++) {
        ans[i][j] = 1;
        if(isvalid(ans, n,i, j)) {
            
            if(nQueen(n, ans, i + 1)) {
                res.push_back(ans);
            }
            
        }
        ans[i][j] = 0;
    }
    
    return false;
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int> > ans(n, vector<int> (n, 0));
//     return ans;
     vector<vector<int> > r;
    if(n == 1){
        return {{1}};
    }
    if(n <= 3) {
        return r;
    }
    nQueen(n, ans, 0);
    vector<vector<vector<int > > > t = res;
    res.clear();
   
    
    for(auto i : t) {
        vector<int> l;
        for(auto j : i) {
            for(auto k : j) {
                l.push_back(k);
            }
        }
        r.push_back(l);
    }
    return r;
    
    
    
}