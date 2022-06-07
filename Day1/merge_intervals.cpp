#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int> > ans;
    int i = 0;
    while(i < intervals.size()) {
        auto it = intervals[i];
        
        int j = i + 1;
        
        while(j < intervals.size() and intervals[j][0] <= it[1]) {
            it[1] = max(it[1], intervals[j][1]);
            j++;
        }
        i = j;
        ans.push_back(it);
     }
    return ans;
}
