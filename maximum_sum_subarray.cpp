long long maxSubarraySum(int v[], int n)
{
    long long sum = 0;
    long long ans = 0;
    int i = 0;
    int j = 0;
    while(i < n and j < n) {
        sum += v[j];
        while(i <= j and sum < 0) {
            sum -= v[i];
            i++;
        }
        ans = max(ans, sum);
        j++;
    }
    return ans;
}