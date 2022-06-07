#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int a = arr[n / 3];
    int b = arr[(2 * n) / 3];
    
    int cnt = 0;
    for(auto i : arr) {
        if(i == a) cnt++;
    }
    vector<int> ans;
    if(cnt > n / 3) {
        ans.push_back(a);
    }
    cnt = 0;
    for(auto i : arr) {
        if(i == b) cnt++;
    }
    if(cnt > n / 3) {
        ans.push_back(b);
    }
    if(ans.size() > 1) {
        if(ans.back() == ans.front()) 
        {
            ans.pop_back();
        }
    }
    return ans;

}