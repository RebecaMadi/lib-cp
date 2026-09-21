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
    int m;

    autKMP(string s) {
        m = s.size();
        vector<int> p = PI(s);

        // estados 0 ... m
        nxt.assign(26, vector<int>(m + 1));

        for (int c = 0; c < 26; c++) {
            // estado 0
            nxt[c][0] = (c == s[0] - 'a');
            for (int j = 1; j < m; j++) {
                if (c == s[j] - 'a') nxt[c][j] = j + 1;
                else nxt[c][j] = nxt[c][p[j - 1]];
            }
            // estado m: acabamos de encontrar o padrão
            nxt[c][m] = nxt[c][p[m - 1]];
        }
    }
};

int matching(string t, string s) {
    if (s.empty()) return 0;
    auto aut = autKMP(s);
    int at = 0;
    int match = 0;
    for (char ch : t) {
        at = aut.nxt[ch - 'a'][at];
        if (at == s.size()) {
            match++;
            at = aut.nxt[ch - 'a'][at];
        }
    }
    return match;
}
