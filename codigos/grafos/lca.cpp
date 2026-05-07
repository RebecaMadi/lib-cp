const int logn = 20;
vector<int> lvl(MAX);

vector<vector<int>> anc(MAX, vector<int>(logn));
auto dfs = [&](auto &dfs, int u, int p, int w) -> void {
    anc[u][0] = p;
    for(int i=1; i<logn; i++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(auto [peso, v] : g[u]){
        if(v == p) continue;
        lvl[v] = lvl[u] + 1;
        dfs(dfs, v, u, peso);
    }
};

auto lca = [&](int a, int b) {
    if(lvl[a] < lvl[b]) swap(a, b);
    int dif = lvl[a] - lvl[b];
    for(int i = logn-1; i>=0; i--) {
        if((1<<i) <= dif) {
            a = anc[a][i];
            dif -= (1 << i);
        }
    }
    if(a==b) return a;
    for(int i=logn-1; i>=0; i--) {
        if(anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
};