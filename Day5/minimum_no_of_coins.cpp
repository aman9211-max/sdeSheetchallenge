#include<bits/stdc++.h>

int findMinimumCoins(int amount) 
{
    // Write your code here
    int ans = 0;
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};\
    for(int i = 8; i >= 0; i--) {
        if((amount / arr[i])  >= 1) {
            ans += (amount / arr[i]);
            amount = amount % arr[i];
        }
        if(amount == 0) {
            break;
        }
    }
    
    return ans;
    
}
