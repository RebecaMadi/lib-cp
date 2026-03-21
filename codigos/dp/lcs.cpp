for(int i=1; i<=m; i++)
{
    for(int j=1; j<=n; j++)
    {
        if(a[j]==b[i]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
    }
}
// tamanho da LCS: dp[m][n]

// constroi a LCS
int i=m, j=n; 
while(i>0 && j>0)
{
    if(a[j]==b[i]) seq.pb(a[j]), j--, i--;
    else if(dp[i-1][j] >= dp[i][j-1]) i--;
    else j--;
}
reverse(seq.begin(), seq.end());