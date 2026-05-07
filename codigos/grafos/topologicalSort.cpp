int n;
vector<int> g[26];
int vis[26];
string name[maxn];
string ans;

bool dfs(int u){
    vis[u] = VISITTING;

    for(auto v:g[u]){
        if(vis[v]== VISITTING || vis[v]==UNVISITED && !dfs(v) ) return false;
    }

    vis[u] = VISITED;
    ans += u + 'a';

    return true;
}

// Ordena topologicamente um alfabeto e detecta ciclo 
bool topSort(){
    fill(vis, vis+26, UNVISITED);

    forn(i,0,25){
        if(vis[i]==UNVISITED && !dfs(i)) return false;
    }

    reverse(all(ans));
    return true;
}
