vector<int> PI(string s) {
    int n = s.size();
    vector<int> p(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
 
struct autKMP {
    vector<vector<int>> nxt;
    vector<int> pi;
    int m;
 
    autKMP(string s) {
        m = s.size();
        pi = PI(s);
        nxt.assign(26, vector<int>(m + 1));
 
        for (int c = 0; c < 26; c++) {
            nxt[c][0] = (c == s[0] - 'a');
            for (int j = 1; j <= m; j++) {
                if (j < m && c == s[j] - 'a') nxt[c][j] = j + 1;
                else nxt[c][j] = nxt[c][pi[j - 1]];
            }
        }
    }
};
 
int matching(string t, string s) {
    auto aut = autKMP(s);
    int at = 0;
    int match = 0;
    for (char c : t) {
        at = aut.nxt[c - 'a'][at];
        if(at == s.size()) match++;
    }
    return match;
}
