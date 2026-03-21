// Bellman-Ford - menor caminho de fonte única (aceita pesos negativos)
// Complexidade: O(V * E)

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

int n, m;
vector<Edge> edges;
long long dist[MAXN];

// retorna true se não há ciclo negativo alcançável a partir de src
bool bellmanFord(int src) {
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // checa ciclo negativo
    for (auto &[u, v, w] : edges) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            return false; // ciclo negativo detectado
        }
    }
    return true;
}
