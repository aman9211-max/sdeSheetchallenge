#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans = 0;
    map<int, int> vis;
    int i =0 ;
    int j = 0;
    while(i < input.size() and j < input.size()) {
        vis[input[j]]++;
        while(i <= j and vis[input[j]] > 1) {
            vis[input[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}