#include<bits/stdc++.h>


bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int> > ans;
    int n = start.size();
    for(int i = 0; i < n; i++) {
        ans.push_back({start[i], finish[i]});
    }
    
    sort(ans.begin(), ans.end(), comp);
    
    int i = 0;
    int cnt = 1;
    
    for(int j = 1; j < n; j++) {
        if(ans[j].first >= ans[i].second) {
            cnt++;
            i = j;
        }
    }
    return cnt;
}