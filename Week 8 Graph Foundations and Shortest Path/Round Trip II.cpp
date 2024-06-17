#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
vector<int> state;
vector<vector<int>> g;
bool is_cycle = false;
void dfs(int node)
{
    state[node] = 2;
    for (auto v : g[node])
    {
        if (state[v] == 0)
        {
            dfs(v);
        }
        else if (state[v] == 2)
        {
            is_cycle = true;
        }
    }
    state[node] = 3;
}
void solve()
{
    is_cycle = false;
    state.clear();
    g.clear();
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    state.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
        {
            dfs(i);
        }
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
        if (is_cycle)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}