#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	map<int, int> m;
    for(auto i : arr) {
        m[i]++;
        if(m[i] > 1) {
            return i;
        }
    }
        
}
