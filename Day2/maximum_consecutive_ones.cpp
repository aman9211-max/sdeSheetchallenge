int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    
    int i = 0;
    int j = 0;
    int ans = 0;
    int cnt0= 0;
    int cnt1 = 0;
    
    while(i < arr.size() and j < arr.size()) {
        cnt0 += (arr[j] == 0);
        cnt1 += (arr[j] == 1);
        while(i <= j and cnt0 > k) {
            cnt0 -= (arr[i] == 0);
            cnt1 -= (arr[i] == 1);
            i++;
        }
        ans = max(ans, cnt1 + cnt0);
        j++;
    }
    return ans;
    
}
