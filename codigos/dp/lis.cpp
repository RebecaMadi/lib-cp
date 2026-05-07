// O(n log n)
int lis(vector<int> const& a) {
    vector<int> dp(n+1, INF);
    dp[0] = -INF;
    for(int i=1; i<=n; i++) {
        auto it = upper_bound(all(dp), a[i]) - dp.begin();
        if(dp[it-1] < a[i] && a[i] < dp[it]) dp[it] = a[i];
    }
    int ans = 1;
    for(int i=1; i<=n; i++)
        if(dp[i]!=INF) ans = i;
    return ans;
}

// O(nˆ2)
vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}