struct Node {
    char value;
    bool fim; // marca o fim de uma palavra
    unordered_map<char, Node*> mp; // mapa de caracteres para os próximos nós

    Node(char v, bool f) : value(v), fim(f) {}
};

void insert(string s, Node* root)
{
    Node* aux = root;

    for (auto c : s)
    {
        if (aux->mp.find(c) == aux->mp.end()) aux->mp[c] = new Node(c, false);
        aux = aux->mp[c];
    }
    aux->fim = true;
}

void search(string& s, Node* root, int pos)
{
    Node* aux = root;
    string ans = "";
    for (int i=pos; i<sz(s); i++)
    {
        char c = s[i];
        if (aux->mp.find(c) == aux->mp.end()) return;
        ans += c;
        if(aux->mp[c]->fim){ // econtra uma palavra
            if(dp[i+1]) dp[pos] = true, dps[pos] = ans;
        }
        aux = aux->mp[c];
    }
}
