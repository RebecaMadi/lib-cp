template <typename T>

// calcula n^p mod m em O(log p)
T fexp(T n, T p, T mod) {
    T val = 1;
    n %= mod;
    while (p) {
        if (p & 1) val = val * n % mod;
        n = n * n % mod;
        p >>= 1;
    }
    return val;
}

// exemplo de uso:
// ll ans = fexp<ll>(2, 10, 1e9 + 7);

// Inverso modular:
// para calcular a^(-1) mod m, onde m é primo, basta usar fexp(a, m - 2, m)