struct DSU {
    vector<int> parent, rank, size;
    int n;

    DSU(int n)
    {
        this->n = n+1;
        parent.assign(this->n, 0);
        rank.assign(this->n, 0);
        size.assign(this->n, 0);
    }

    void make_set(int v)
    {
        parent[v] = v;crank[v] = 0; size[v] = 1;
    }

    int find_set(int v)
    {]
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if(a!=b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;

            // altura = max(rank[a], rank[b]), se rank[a] > rank[b] nada muda, se forem iguais então a altura aumenta
            if(rank[a] == rank[b]) rank[a]++; 
            size[a] += size[b];
        }
    }

    int query(int v)
    {
        v = find_set(v);
        return (int) (size[v] * (size[v]-1))/2; // alterar dependendo do que se queira consultar, nesse caso é o número de pares dentro do mesmo conjunto
    }
};