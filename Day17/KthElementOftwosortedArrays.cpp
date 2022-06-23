#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int ans = INT_MAX;
    int s = 0;
    int e = 100005;
    
    while(s <= e) {
        int mid = (s + e) >> 1;
        int cnt = upper_bound(row1.begin(), row1.end(), mid) - row1.begin();
        cnt += upper_bound(row2.begin(), row2.end(), mid) - row2.begin();
        if(cnt >= k) {
            ans = min(ans , mid);
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}