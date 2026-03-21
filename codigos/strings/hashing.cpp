// hash[s] = somatorio de (s[i] - 'a' + 1) * p^i mod m
long long compute_hash(string const& s) {
    const int p = 31; // lower case, 53 to include upper case
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}