void dfs(int i, int pai) {
    vis[i] = 1;
    int cont = 0;
    for(auto [w, u] : g[i]) {
        if(!vis[u]) dfs(u, i);
        if(u == pai) continue;
        cont++;
        if(maior[u].fr + 1 >= maior[i].fr) {
            maior[i] = {maior[u].fr+1, u};
            folha[i] = folha[u];
        }
    }
    if(!cont) folha[i] = i;
    //cout << "i: " << i << " maior: " << maior[i].fr << " " << maior[i].sc << endl;
    for(auto [w, u] : g[i]) {
        if(u==pai || u==maior[i].sc) continue;
        if(ans <= maior[i].fr + 1 + maior[u].fr ) {
            ans = max(ans, maior[i].fr + 1 + maior[u].fr);
            d.fr = folha[i], d.sc = folha[u];
        }
    }
}
