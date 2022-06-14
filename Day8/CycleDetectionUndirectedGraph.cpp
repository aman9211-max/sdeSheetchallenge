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
    //  if (parent[v] == v) {
    //      return v;
    //  }
    //  return get(parent[v]); //  o(n)  : time complexity
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
        else {
            if (size[spa] <  size[spb]) {
                swap(spa, spb);
            }
            size[spa]++;

        }

    }
};

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    
    dsu g(n + 1);
    for(auto i : edges) {
        if(g.get(i[0]) == g.get(i[1])) {
            return "Yes";
        }
        else {
            g.union_set(i[0], i[1]);
        }
    }
    return "No";
}

