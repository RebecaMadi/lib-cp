struct node { 
    ll par = 0, l = 0, r = 0; 
};

vector<node> tree(MAX);
vector<ll> a(MAX);
int n;

void solve() {
    cin >> n;
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
    while(tree[root].par != 0) root = tree[roor].par;
}
