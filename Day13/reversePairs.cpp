#include <bits/stdc++.h> 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	]
    
    indexed_multiset st;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += st.order_of_key(arr[i]);
        st.insert(2 * arr[i]);
    }
    return ans;
    
}