#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    
    int s = 0;
    int e = m - 1;
    
//     cout << s << endl;
    int row = s;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(mat[mid][0] == target) {
            return true;
        }
        else if(mat[mid][0] < target) {
            row = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    int l = 0;
    int r = n - 1;
    
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(mat[row][mid] == target) {
            return true;
        }
        else if(mat[row][mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return 0;
    
}