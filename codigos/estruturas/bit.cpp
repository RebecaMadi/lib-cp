typedef struct ftree {
    vector<int> BIT;
    int n;

    ftree(int n){
        this->n = n + 1;
        BIT.assign(n + 1, 0);
    }

    int query(int i)
    {
        int ans = 0;
        for(; i>0; i -= i&(-i)) ans += BIT[i];
        return ans;
    }

    void update(int i, int n, int v)
    {
        for(; i<=n; i += i&(-i)) BIT[i] += v;
    }
} FTree;