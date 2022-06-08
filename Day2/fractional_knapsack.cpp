#include<bits/stdc++.h>

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return (double) ((double) a.second / a.first) > ((double) b.second / b.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    sort(items.begin(), items.end(), comp);

    double ans = 0;
     int i = 0;
    while(i < items.size() and w - items[i].first >= 0) {
        w -= items[i].first;
        ans += items[i].second;
        i++;
    }
    if(w != 0 and i < items.size()) {
        ans += (double) ((double) w / (items[i].first) * items[i].second);
    }
    return ans;
    
}