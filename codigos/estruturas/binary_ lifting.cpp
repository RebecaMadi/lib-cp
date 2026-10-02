int up[MAX][LOG], parent[MAX];

for(int i=1; i<=n; i++) up[i][0] = parent[i];

for(int j=1; j<LOG; j++) {
    for(int i=1; i<=n; i++)
        up[i][j] = up[up[i][j-1]][j-1];
}

auto query = [&](int x, int k) -> int {
    for(int j = 0; j < LOG; j++) 
        if(k & (1 << j)) x = up[x][j];
    return x;
};
