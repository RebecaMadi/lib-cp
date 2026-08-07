// Dijkstra - menor caminho de fonte única
// Complexidade: O((V + E) log V)

const int INF = 1e18;
const int MAXN = 1e5 + 5;

vector<pair<int,int>> adj[MAXN];
long long dist[MAXN];

void dijkstra(int src, int n) {
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
