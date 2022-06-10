


bool find(vector<int> &arr, int i, int k, vector<vector<int> > &dp) {
    if(k == 0) {
        return 1;
    }
    if(k < 0) 
    {
        return 0;
    }
    if(i == arr.size()) {
        return 0;
        
    }
    
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    
    bool op1 = find(arr, i + 1, k - arr[i], dp);
    bool op2 = find(arr, i + 1, k, dp);
    return dp[i][k] =  (op1 || op2);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int> > dp(n + 1, vector<int> (k + 1, -1));
    return find(arr, 0, k, dp);
    
}