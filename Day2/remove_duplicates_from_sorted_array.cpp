int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int i = 1; int cnt = 1;
    
    while(i < n) {
        while(i < n and arr[i] == arr[i - 1]) {
            i++;
        }
        if(i < n) {
            cnt++;
            i++;
        }
    }
    
    return cnt;
}