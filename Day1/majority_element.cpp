#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    
    
    sort(arr, arr + n);
    int t =  arr[n / 2];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == t) cnt++;
    }
    if(cnt <= n / 2) return -1;
    return t;
}