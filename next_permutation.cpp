#include <bits/stdc++.h> 

void reverse(vector<int> &p, int l, int r) {
    while(l <= r) {
        swap(p[l++], p[r--]);
    }
}
int indx(vector<int> &p, int i, int key) {
    int s = i;
    int e = p.size() - 1;
    int index = -1;
    while(s <= e) {
        int mid = (s + e) >> 1;
        if(p[mid] <=key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
            if(index == -1 || p[index] >= p[mid]) {
                index = mid;
            }
        }
    }
    return index;
}
vector<int> nextPermutation(vector<int> &p, int n)
{
    //  Write your code here.
    int i = n - 2;
    
    while(p[i] >= p[i + 1]) {
        i--;
    }
    
    if(i < 0) {
        reverse(p.begin(), p.end());
        return p;
    }
    
    int index = indx(p, i + 1, p[i]);
    swap(p[i], p[index]);
    
    reverse(p, i + 1, n - 1);
    return p;
    
    
}