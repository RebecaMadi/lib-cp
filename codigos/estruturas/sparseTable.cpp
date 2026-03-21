int K=20, MAX=1e5+5; // K = log2(MAX)
int st[K+1][MAX], lg[MAX];
vector<int> v(MAX);

void init(int n)
{
    for(int i=0; i<n; i++) st[0][i] = v[i];

    for(int i = 1; i<=K; i++)
    {
        for(int j=0; j + (1<<i) <=n; j++) st[i][j] = gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    }

    // pre computa os logs dos tamanhos (floor)
    lg[1] = 0;
    for(int i=2; i<=n; i++) lg[i] = lg[i/2] + 1;
}

int query(int L, int R)
{
    int i = lg[R-L+1];
    return gcd(st[i][L], st[i][R - (1<<i) + 1]);
    // Ex: R = 30, L = 16, dist = 15, log2(15) = 3
    // Não tem problema a sobreposicao. O(1)
    // gcd(intervalo de tamanho 2ˆ3 comecando em L(16), intervalo de tamanho 2ˆ3 comecando em 23)
}