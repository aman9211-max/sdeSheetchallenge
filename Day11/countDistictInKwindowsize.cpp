#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	map<int, int> cnt;
    for(int i = 0; i < k; i++) {
        cnt[arr[i]]++;
    }
    vector<int> ans;
    ans.push_back(cnt.size());
    int s = 0;
    for(int i = k; i < arr.size(); i++) {
        cnt[arr[i]]++;
        cnt[arr[s]]--;
        if(cnt[arr[s]] == 0) {
            cnt.erase(arr[s]);
        }
        s++;
        ans.push_back(cnt.size());
    }
    return ans;
}
