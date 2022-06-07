#include <bits/stdc++.h> 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

long long getInversions(long long *arr, int n){
    long long ans = 0;
    indexed_multiset st;
    for(int i = n - 1; i >= 0; i--) {
        ans += st.order_of_key(arr[i]);
        st.insert(arr[i]);
    }
    return ans;
    
    
}