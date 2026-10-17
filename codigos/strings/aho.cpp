#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define endl "\n"
using namespace std;

const int INF = 1e9;
const int MAXN = 5e5 + 7;
const int MAXT = 1e5 + 7;
using pii = pair<int,int>;
using tii = tuple<int, int, int>;

struct node {
    map<int, int> ch; // transicoes
    int suf;  // suffix link
    bool end; // fim de um gene
    int par;  // pai
    int id;   // indice do gene que termina aqui
    int len;  // profundidade = tamanho do gene
    int ex;   // primeiro no com end = true subindo pelos suffix links e com o menor id
};

node aho[MAXN];
int tt;

void add(string &s, int id) {
    int cur = 0;
    for(auto c : s) {
        if(!aho[cur].ch.count(c)) {
            aho[++tt].ch.clear();
            aho[cur].ch[c] = tt;
            aho[tt].par = cur;
            aho[tt].end = false;
            aho[tt].suf = 0;
            aho[tt].len = aho[cur].len + 1;
        }
        cur = aho[cur].ch[c];
    }
    aho[cur].end = true;
    aho[cur].id = id;
}

int nxt(int j, int c) {
    while(j && aho[j].ch.count(c) == 0) j = aho[j].suf;
    if(aho[j].ch.count(c)) j = aho[j].ch[c];
    return j;
}

void build_aho() {
    queue<pii> q;
    for(auto & [c, it] : aho[0].ch) q.push({c, it});

    while(!q.empty()) {
        auto [c, it] = q.front(); q.pop();
        if(aho[it].par) {
            aho[it].suf = nxt(aho[aho[it].par].suf, c);
        }

        aho[it].ex = aho[aho[it].suf].ex;
        if(aho[it].end && (!aho[it].ex || aho[it].id < aho[aho[it].ex].id)) aho[it].ex = it;

        for(auto & [cc, itt] : aho[it].ch) q.push({cc, itt});
    }
}

int tree[1<<21];
int n;

int query(int a, int b) {
	int ret = INF;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = min(ret, tree[a]);
		if (b % 2 == 0) ret = min(ret, tree[b]);
	}
	return ret;
}

void upd(int p, int x) {
    p += n;
	tree[p] = min(x, tree[p]);
    //cout << x << "\n";
	while (p /= 2)tree[p] = min(tree[2*p], tree[2*p+1]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin >> t;
    n = sz(t);

    int g; cin >> g;
    for(int i=1; i<=g; i++) { 
        string s; cin >> s; 
        add(s, i); 
    }
    build_aho();

    int q; cin >> q;
    vector<tii> qs(q);
    for(int i=0; i<q; i++) { 
        int L, R; cin >> L >> R; 
        qs[i] = {R, L, i}; 
    }

    // inicialmente a seg vai estar vazia, preciso consultar depois de inserir
    sort(all(qs));

    for(int i=0; i<(1<<21); i++) tree[i] = INF;

    vector<int> ans(q, -1);
    int cur = 0, j = 0;
    for(int r=1; r<=n; r++) {
        cur = nxt(cur, t[r-1]);

        // todo gene que termina em r vamos marcar a posicao onde ele começa
        for(int u = aho[cur].ex; u; u = aho[aho[u].suf].ex)
            upd(r - aho[u].len, aho[u].id);

        while(j < q) {
            auto [R, L, id] = qs[j];
            if(R > r) break;
            j++;
            int res = query(L-1,n-1);
            //cout << "L: " << L << " R: " << R << endl;
            //cout << "res: " << res << endl;
            ans[id] = (res == INF ? -1 : res);
        }
    }

    for(int i=0; i<q; i++) cout << ans[i] << endl;
    return 0;
}
