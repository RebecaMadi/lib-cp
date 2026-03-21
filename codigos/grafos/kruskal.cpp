// Kruskal - Árvore Geradora Mínima (MST)
// Complexidade: O(E log E)

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &o) const { return w < o.w; }
};

int par[MAXN], rnk[MAXN];

void init(int n) {
    for (int i = 0; i <= n; i++) par[i] = i, rnk[i] = 0;
}

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool union_sets(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

// Retorna o custo da mst. Se não for conexo, retorna -1
long long kruskal(int n, vector<Edge> &edges) {
    init(n);
    sort(edges.begin(), edges.end());

    long long cost = 0;
    int cnt = 0;

    for (auto &[u, v, w] : edges) {
        if (union_sets(u, v)) {
            cost += w;
            if (++cnt == n - 1) break;
        }
    }

    return cnt == n - 1 ? cost : -1;
}
