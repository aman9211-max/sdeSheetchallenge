#include <bits/stdc++.h> 
using namespace std;
string fourSum(vector<int> arr, int target, int n) {
   
    sort(arr.begin(), arr.end());
    
    for(int i = 0 ; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            int find = (target - (arr[i] + arr[j]));
            int s = i + 1;
            int e = j - 1;
            
            while(s < e) {
                if(arr[s]+ arr[e] == find) {
                    return "Yes";
                }
                else if(arr[s] + arr[e] < find) {
                    s++;
                }
                else {
                    e--;
                }
            }
            
            
        }
    }
    return "No";
}
