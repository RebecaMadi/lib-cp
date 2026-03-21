// funcao de prefixo
vector<int> PI(string s)
{
    vector<int> p(s.size()+1, 0);

    for(int i = 1, j = 0; i < s.size(); i++)
    {
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

// KMP autômato
struct autKMP {
    vector<vector<int>> nxt;

    autKMP(string s) : nxt(26, vector<int>(s.size()+1)) {
        vector<int> p = PI(s+'$');
        nxt[s[0]-'A'][0] = 1;
        for(char c = 0; c<26; c++) // nova transição
            for(int j = 1; j <= s.size(); j++) // tamanho
                nxt[c][j] = c == s[j] ? j+1 : nxt[c][p[j-1]], freq[nxt[c][j]]++;
     }
};

int matching(string t, string s) {
    int match = 0;
    auto aut = autKMP(s);
    int at = 0;
    for(int i=0; i<sz(t); i++)
    {
        at = aut.nxt[t[i]-'A'][at];
        if(at == sz(s)) match++;
    }
    return match;
}
