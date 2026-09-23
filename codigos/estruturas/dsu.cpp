struct DSU {
    vector<int> parent, size;
    int n, gt;
 
    DSU(int n) {
        this->n = n + 1;
        parent.resize(this->n);
        size.assign(this->n, 1);
        gt = 1;
        for(int i = 1; i <= n; i++) make_set(i);
    }
 
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
 
    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }
 
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
 
        if(a == b) return;
 
        // small-to-large
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        gt = max(gt, size[a]);
    }
 
    int query(int v) {
        v = find_set(v);
        return 1LL * size[v] * (size[v] - 1) / 2;
    }
};
