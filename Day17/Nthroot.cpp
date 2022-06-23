

double multiply(double mid, double n, double m) {
    double ans = 1.0;
    for(double i = 0; i < n; i++) {
        ans = ans * mid;
        if(ans > m) {
            return m + 1;
        }
    }
    return ans;
}

double findNthRootOfM(double n, long long m) {
    double s = 1;
    double e = m;
    double eps = 1e-7;
    while((e - s) >= eps) {
        double mid = (s + e) / 2.0;
        if(multiply(mid, n, m) < m) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    return s;    
}
