#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
vector<vector<int>> g;
vector<int> vis;
void bfs(int node)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        for (auto i : g[ele])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
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
    vis.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num++;
            bfs(i);
        }
    }
    cout << num - 1;

    return 0;
}