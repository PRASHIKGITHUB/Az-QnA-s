#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
lli m = 1e9 + 7;
vector<vector<int>> g;
vector<int> color;
vector<int> vis;
vector<int> colNum;
void dfs(int node, int col)
{
    vis[node] = 1;
    color[node] = col;
    colNum[col]++;
    for (auto i : g[node])
    {
        if (!vis[i])
        {
            dfs(i, col);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1);
    vis.resize(n + 1);
    colNum.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int col = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            col++;
            dfs(i, col);
        }
    }
    lli ans = 0;
    lli sum = 0;
    for (int i = 1; i <= col; i++)
    {
        sum += colNum[i];
    }
    for (int i = 1; i <= col; i++)
    {
        ans += colNum[i] * (sum - colNum[i]);
        sum -= colNum[i];
    }

    cout << ans << endl;
    return 0;
}