#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
lli m = 1e9 + 7;

vector<vector<int>> g;
vector<int> vis;
vector<int> color;
vector<int> colnum;
void dfs(int node, int col)
{
    vis[node] = 1;
    color[node] = col;
    colnum[col]++;
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

    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n + 1);
    vis.resize(n + 1);
    color.resize(n + 1);
    colnum.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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

    while (q--)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            int x;
            cin >> x;
            cout << colnum[color[x]] << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (color[x] == color[y])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}