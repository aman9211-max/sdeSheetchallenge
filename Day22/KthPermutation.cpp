


string kthPermutation(int n, int k) {
    vector<int> arr;
    for(int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    int fact = 1;
    for(int i = 2; i <= n; i++) {
        fact *= i;
    }
    k--;
    string ans;
    while(arr.size() > 0) {
        int div = fact / n;
        ans += to_string(arr[k/div]);
        arr.erase(arr.begin() + (k / div));
        k %= div;
        fact /= n;
        n--;
        
    }
//     cout << ans << endl;
    return ans;
}
