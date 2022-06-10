#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
   map<int, int> m;
    int ans = 0;
    m[0] = 1;
    for(int i = 1; i < arr.size(); i++) {
        arr[i] ^= arr[i - 1];
        
    }
    
    for(int i = 0; i < arr.size(); i++) {
        ans += m[arr[i] ^ x];
        m[arr[i]]++;
    }
    return ans;
}