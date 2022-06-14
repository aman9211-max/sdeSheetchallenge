#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


bool comp(vector<int>  &a, vector<int> & b) {
	return (a[1] == b[1]) ? (a[2] < b[2]) : a[1] < b[1];
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
	vector<vector<int> > ans;
    for(int i = 0; i < start.size(); i++) {
        ans.push_back({start[i], end[i], i});
    }
    
    sort(ans.begin(), ans.end(), comp);
    int cnt = 1;
    vector<int> res;
    res.push_back(ans[0][2] + 1);
    int prev = ans[0][1];
   for(int i = 1; i < ans.size(); i++) {
      if(ans[i][0] > prev) {
          res.push_back(ans[i][2] + 1);
          prev = ans[i][1];
      }
   }
//     sort(res.begin(), res.end());
    return res;
}