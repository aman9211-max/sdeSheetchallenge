#include<bits/stdc++.h>

int ispossible(vector<vector<int> > &matrix, int m) {
    int ans = 0;
    for(int i = 0; i < matrix.size(); i++) {
        int s = 0;
        int e = matrix[0].size() - 1;
        int indx = -1;
        while(s <= e) {
            
            int mid = (s + e) >> 1;
            if(matrix[i][mid] <= m) {
                indx = mid;
                s = mid + 1;
            }
            else {
               e = mid - 1;
            }
           
        }
        ans += (indx + 1);
        
    }
    return ans;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
   int s =  0;
   int  e  = 100005;
    int ans = matrix[n - 1][n - 1];
    while(s < e) {
        int mid =  s + (e - s) / 2;
         if(ispossible(matrix, mid) >= (m * n) / 2 + 1) {
             ans = mid;
            e = mid ;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}