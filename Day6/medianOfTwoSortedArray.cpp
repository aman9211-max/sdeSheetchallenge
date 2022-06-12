#include<bits/stdc++.h>

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    if(a.size() > b.size()) {
        return median(b, a);
    }
    
    int n = a.size();
    int m = b.size();
    
    int s = 0;
    int e = n;
    
    while(s <= e) {
        int mida = (s + e) >> 1;
        int midb = (n + m + 1) / 2 - mida;
        int maxlefta = ((mida == 0) ? INT_MIN : a[mida - 1]);
        int maxleftb = ((midb == 0) ? INT_MIN : b[midb - 1]);
        int minrighta = ((mida == n) ? INT_MAX : a[mida]);
        int minrightb = ((midb == m) ? INT_MAX : b[midb]);
        
        if(maxlefta <= minrightb and maxleftb <= minrighta) {
            if((n + m)%2 == 0)
                return (max(maxlefta, maxleftb) + min(minrighta, minrightb)) / 2.00;
            else {
                return max(maxlefta, maxleftb);
            }
        }
        else if(maxlefta > minrightb) {
            e = mida - 1;
        }
        else {
            s = mida + 1;
        }
    }
    return -1;
    
}
