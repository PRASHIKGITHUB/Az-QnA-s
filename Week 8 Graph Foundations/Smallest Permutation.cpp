#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
void khan()
{
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(-i);
        }
    }
    while (!pq.empty())
    {
        int v = -pq.top();
        pq.pop();
        topo.push_back(v);
        for (auto i : g[v])
        {
            indeg[i]--;
            if (indeg[i] == 0)
            {
                pq.push(-i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    indeg.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        indeg[b]++;
    }
    khan();
    if (topo.size() != n)
    {
        cout << "-1";
    }
    else
    {
        for (auto i : topo)
        {
            cout << i << " ";
        }
    }
    return 0;
}