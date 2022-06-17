#include<bits/stdc++.h>
int LIS(int *arr, int n) {
    int tails[n + 1];
    memset(tails, 0, sizeof tails);
    int size = 0;
    for(int i = 0; i < n; i++)  {
        int x = arr[i];
        int s = 0;
        int e = size;
       while(s < e) {
           int mid = (s + e) >> 1;
           if(x > tails[mid]) {
               s = mid + 1;
           }
           else e = mid;
       }
        tails[s] = x;
        if(s == size) {
            size++;
        }
    }
    return size;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return LIS(arr, n);
}
