
bool ispossible(vector<int> &time, int n, int m, long long mid) {
    long long sum = 0;
    long long cnt = 1;
    
    
    for(int i = 0; i < m; i++) {
        if(time[i] > mid) {
            return false;
        }
        if(sum + time[i] <= mid) {
            sum += time[i];
        }
        else {
            cnt++;
            sum = time[i];
        }
    }
    return cnt <= n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long s = 0;
    
    long long e = 0;
    for(auto i : time) e += i;
    
    
    long long ans = e;
    
    while(s <= e) {
        long long mid = (s + e) >> 1LL;
        if(ispossible(time, n, m, mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    
    return ans;
}