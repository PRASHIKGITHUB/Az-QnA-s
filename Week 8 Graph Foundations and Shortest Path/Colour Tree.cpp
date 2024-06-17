#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;

vector<vector<int>> g;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int temp = 0;
    for (auto i : g)
    {
        temp = max(temp, (int)i.size());
    }
    cout << temp + 1;
    return 0;
}