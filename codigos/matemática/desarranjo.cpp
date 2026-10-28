int fat[MAXN+10], ifat[MAXN+10];
 
int fexp(int n, int p, int mod) {
    int val = 1;
    n %= mod;
    while (p) {
        if (p & 1) val = (__int128) val * n % mod;
        n = (__int128) n * n % mod;
        p >>= 1;
    }
    return val;
}
 
int mult(int a, int b) {
    return (__int128) a * b % MOD;
}
 
void init() {
    fat[1] = fat[0] = 1;
 
    for(int i=2; i<=MAXN; i++) fat[i] = mult(i, fat[i-1]);
    ifat[MAXN] = fexp(fat[MAXN], MOD-2, MOD);
    for(int i=MAXN; i; i--) ifat[i-1] = (__int128) ifat[i]*i%MOD;
}    
 
int comb(int a, int b)  {
    if(b > a) return 0;
    return mult(fat[a], mult(ifat[a-b], ifat[b]));
}
 
int desarranjo(int n) {
    // numero de permutações de n elementos sem nenhuma posição fixa
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int termo = mult(comb(n, i), fat[n-i]);
        if (i % 2 == 0) ans = (ans + termo) % MOD;
        else ans = (ans - termo + MOD) % MOD;
    }
    return ans;
}

