#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    for(int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
    }
    map<int, int> m;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) {
            ans = max(ans, i + 1);
        }
        else if(m.count(arr[i]) > 0) {
            ans = max(ans, i - m[arr[i]] );
        }
        else {
            m[arr[i]] = i;
        }
    }
    
    return ans;
    

}