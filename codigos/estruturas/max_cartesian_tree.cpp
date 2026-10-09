struct node { 
    ll par = 0, l = 0, r = 0; 
};

void reset(int n) {
    for(int i=0; i<=n; i++) tree[i].par = tree[i].l = tree[i].r = 0;
}

void inorder(int v) {
    if (v == 0) return;

    inorder(tree[v].l);
    cout << v << ' ';
    inorder(tree[v].r);
}

void solve() {
    int n;
    cin >> n;
    reset(n);
    for(int i=1; i<=n; i++) cin >> a[i];

    stack<int> st;

    for(int i=1; i<=n; i++) {
        int last = 0;
        while(sz(st) && a[st.top()] < a[i]) {
            last = st.top();
            st.pop();
        }

        if(last != 0) {
            tree[i].l = last;
            tree[last].par = i;
        }

        if(sz(st)) {
            tree[st.top()].r = i;
            tree[i].par = st.top();
        }

        st.push(i);
    }

    int root = 1;
    while(tree[root].par != 0) root = tree[root].par;
    inorder(root);
}
