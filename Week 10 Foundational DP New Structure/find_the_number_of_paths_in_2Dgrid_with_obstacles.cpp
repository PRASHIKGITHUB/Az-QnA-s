#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
lli M = 1e9 + 7;
int n, m, k;
lli arr[201][201];
lli dp[201][201][401];
lli rec(int r, int c, int k)
{

    // pruning
    if (r < 1 || c < 1)
    {
        return 0;
    }
    // base case
    if (r == 1 && c == 1)
    {
        return 1;
    }
    // cache check
    if (dp[r][c][k] != -1)
    {
        return dp[r][c][k];
    }
    // transition
    lli ans = 0;

    if (c > 1)
    {
        if (arr[r][c - 1] == 0)
        {
            ans = (ans % M + rec(r, c - 1, k) % M) % M;
        }
        else if (k >= 1)
        {
            ans = (ans % M + rec(r, c - 1, k - 1) % M) % M;
        }
    }

    if (r > 1)
    {
        if (arr[r - 1][c] == 0)
        {
            ans = (ans % M + rec(r - 1, c, k) % M) % M;
        }
        else if (k >= 1)
        {
            ans = (ans % M + rec(r - 1, c, k - 1) % M) % M;
        }
    }

    // save and return
    return dp[r][c][k] = ans%M;
}
void solve()
{
    cin >> n >> m >> k;
    // memset(dp, -1, sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int h=0;h<=k;h++){
                dp[i][j][h]=-1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    //checking for the last element itself before calling rec if it's already 0
    if(arr[n][m]==0){//0 means free block
        cout<<rec(n,m,k)<<endl;
    }
    else if(k>=1){
        cout<<rec(n,m,k-1)<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
