#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n, m;
vector<int> color;
int col;
bool is_valid = true;
vector<vector<int>> g;
void dfs(int node)
{
    color[node] = col;
    col = 1 ^ 2 ^ col;
    for (auto v : g[node])
    {
        if (color[v] == 0)
        {
            dfs(v);
        }
        else if (color[v] != col)
        {
            is_valid = false;
        }
    }
    col = 1 ^ 2 ^ col;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    color.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    col = 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i);
        }
    }
    if (is_valid)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}