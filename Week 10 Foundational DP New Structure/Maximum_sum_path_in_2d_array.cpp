#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int n, m;
int dp[1001][1001];
int vis[1001][1001];
int rec(int r, int c)
{
    if (r < 0 || c < 0)
    {
        return -1e9;
    }//pruning
    if(r==0 && c==0){
        return arr[0][0];
    }//base case

    if(vis[r][c]){
        return dp[r][c];
    }
    int ans=-1e9;
    ans=max(rec(r,c-1)+arr[r][c],rec(r-1,c)+arr[r][c]);
    vis[r][c]=1;
    return dp[r][c]=ans;//here dp[r][c] can be -1 as well
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    cout << rec(n - 1, m - 1) << endl;
    return 0;
}