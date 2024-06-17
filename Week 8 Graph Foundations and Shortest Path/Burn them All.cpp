#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
int n, m;
#define MP make_pair
#define F first
#define S second
vector<vector<pp>> g;
vector<int> vis;
vector<lli> dis;
vector<pair<pair<int, int>, int>> edges;
void Dikstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        vis[i] = 0;
    }
    dis[src] = 0;
    priority_queue<pp> pq;
    pq.push(MP(-0, src));
    while (!pq.empty())
    {
        pp T = pq.top();
        pq.pop();
        if (vis[T.S] == 1)
            continue;
        vis[T.S] = 1;
        for (auto v : g[T.S])
        {
            int wt = v.S;
            int nei = v.F;
            if (dis[nei] > dis[T.S] + wt)
            {
                dis[nei] = dis[T.S] + wt;
                pq.push(MP(-dis[nei], nei));
            }
        }
    }
    lli ans = INT_MIN;
    for (auto i : edges)
    {
        lli a = dis[i.F.F];
        lli b = dis[i.F.S];
        lli wt = i.S;
        if (abs(a - b) == wt)
        {
            ans = max(ans, max(a, b) * 10);
        }
        else
        {
            ans = max(ans, (a + b + wt) * 5);
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    dis.resize(n + 1);
    edges.resize(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(MP(MP(a, b), c));
        g[a].emplace_back(MP(b, c));
        g[b].emplace_back(MP(a, c));
    }
    int src;
    cin >> src;
    Dikstra(src);
    return 0;
}