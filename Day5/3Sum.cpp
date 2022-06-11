#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(), arr.end());
    vector<vector<int> > ans;
    for(int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        
        while(l < r) {
            if(arr[l] + arr[r] + arr[i] == K) {
                ans.push_back({arr[i], arr[l], arr[r]});
                int x = arr[l];
                int y = arr[r];
                
                while(l < r and arr[l] == x) l++;
                while(l < r and arr[r] == y) r--;
            }
            else if(arr[l] + arr[r] + arr[i] < K) l++;
            else r--;
        }
        
        while(i + 1 < n and arr[i] == arr[i + 1]) i++;
    }
    return ans;
 }