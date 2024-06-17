#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
int n;
vector<vector<int>> g;
vector<int> parent;
vector<int> depth;
int dia_len;
void dfs(int root, int par, int dep)
{
    parent[root] = par;
    depth[root] = dep;
    for (auto v : g[root])
    {
        if (v != par)
        {
            dfs(v, root, dep + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    g.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0, 0);
    int maxdep_leaf = INT_MIN;
    int maxdep_leaf_index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxdep_leaf < depth[i])
        {
            maxdep_leaf = depth[i];
            maxdep_leaf_index = i;
        }
    }
    dfs(maxdep_leaf_index, 0, 0);

    int last_point = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > dia_len)
        {
            last_point = i;
            dia_len = depth[i];
        }
    }
    if (dia_len % 2 == 0)
    {
        // 1 center
        int par = last_point;
        for (int i = 1; i <= dia_len / 2; i++)
        {
            par = parent[par];
        }
        cout << par << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}