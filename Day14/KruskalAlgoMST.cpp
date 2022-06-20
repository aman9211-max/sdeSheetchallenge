
#include<bits/stdc++.h>
class dsu {

    vector<int> parent;
    vector<int> size;
public:
    dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // int get(int v) {  // it finds the superleader of the given node
    //     if (parent[v] == v) {
    //         return v;
    //     }
    //     return get(parent[v]); //  o(n)  : time complexity
    // }

    int get(int v) {  // it finds the superleader of the given node
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = get(parent[v]); // path compression O(log(n)) : time complexity
    }

    void union_set(int a, int b) {  // it basically merges two superleaders
        int spa = get(a);
        int spb = get(b);


        if (spa != spb) {


            if (size[spa] <  size[spb]) {
                swap(spa, spb);
            }

            size[spa]  += size[spb];
            size[spb] = 0;

            parent[spb] = spa;
        }

    }

};
bool comp(vector<int> &v1,  vector<int> &v2) {
    return v1[2] < v2[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    sort(graph.begin(), graph.end(), comp);
    dsu g(n + 1);
    int ans = 0;
    for(auto i : graph) {
        if(g.get(i[0]) != g.get(i[1])) {
            ans += i[2];
             g.union_set(i[0], i[1]);
        }
    }
    return ans;
}
