#include <bits/stdc++.h> 

long long power(long long n, long long a, long long m) {
    if (a == 0) return 1;

    long long p = power(n, a / 2, m) % m;
    long long temp = (p * p) % m;

    return (a % 2 == 0) ? temp : ((n % m) * (temp % m)) % m;
}
int modularExponentiation(int x, int n, int m) {
	return power(x, n, m);
}