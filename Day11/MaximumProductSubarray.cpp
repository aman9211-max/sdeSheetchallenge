int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int mx, mi;
    mx = mi = arr[0];
    int ans = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < 0) {
            swap(mx, mi);
        }
        mx = max(arr[i], mx * arr[i]);
        mi = min(arr[i], mi * arr[i]);
        
        ans = max(ans, mx);
    }
    return ans;
}
