vector<vector<int> > ans;

void dfs(vector<vector<int> > &m, int i, int j, int n, vector<vector<int> > &t) {
    if(i < 0 || i >= n || j < 0 || j >= n || t[i][j] == 1) {
        return;
    }
    if(m[i][j] == 0) {
        return;
    }
    if(i == n - 1 and j == n - 1) {
        t[i][j] = 1;
        vector<int> c;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                c.push_back(t[row][col]);
            }
        }
        ans.push_back(c);
        t[i][j] = 0;
        return;
    }
    t[i][j] = 1;
    
    
    dfs(m, i + 1, j, n, t);
    dfs(m, i - 1, j, n, t);
    dfs(m, i, j + 1, n, t);
    dfs(m, i, j - 1, n, t);
    t[i][j] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int> > t(n, vector<int> (n, 0));
    
    dfs(maze, 0, 0, n, t);
    vector<vector<int> > res = ans;
    ans.clear();
    return res;
}