#include <bits/stdc++.h> 


void solve(vector<vector<int> > &m, int sx, int sy, int ex, int ey) {
    int e = m[sx][sy];
    
    for(int i = sy + 1; i <= ey; i++) {
        int t = m[sx][i];
        m[sx][i] = e;
        e = t;
    }
    
    for(int i = sx + 1; i <= ex; i++) {
        int t = m[i][ey];
        m[i][ey] = e;
        e = t;
    }
    
    for(int j = ey - 1; j >= sy; j--) {
        int t = m[ex][j];
        m[ex][j] = e;
        e = t;
    }
    
    for(int i = ex - 1; i >= sx; i--) {
        int t = m[i][sy];
        m[i][sy] = e;
        e = t;
    }
}
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int sx = 0;
    int sy = 0;
    int ex = n - 1;
    int ey = m - 1;
    
    while(sx < ex and sy < ey) {
        solve(mat, sx, sy, ex, ey);
        sx++;
        sy++;
        ex--;
        ey--;
    }
}