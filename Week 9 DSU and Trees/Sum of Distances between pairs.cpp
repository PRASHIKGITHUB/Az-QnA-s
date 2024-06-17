#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
int n;
vector<vector<int>> g;
vector<int> par;

vector<int> subtreez;
lli ans;
void dfs(int root, int parent)
{
    par[root] = parent;
    subtreez[root] = 1;
    for (auto v : g[root])
    {
        if (v != parent)
        {
            dfs(v, root);
            subtreez[root] += subtreez[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    par.resize(n + 1);
    subtreez.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        ans += 1LL * subtreez[i] * (n - subtreez[i]);
    }
    cout << ans;
    return 0;
}