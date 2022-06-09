#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	unordered_map<int, int> m;
    for(int i : arr) m[i]++;
    pair<int, int> p = {0, 0};
    for(int  i = 1; i  <= n; i++) {
        if(m[i] > 1) p.second = i;
        if(m[i] == 0) p.first = i;
    }
    
    return p;
	
}
