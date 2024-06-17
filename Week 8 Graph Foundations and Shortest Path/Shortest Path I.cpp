#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
int n, m;
#define MP make_pair
vector<vector<pp>> g;
vector<lli> dis;
vector<int> vis;

void Dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        vis[i] = 0;
    }
    dis[1] = 0;
    priority_queue<pp> pq;
    pq.push(MP(-0, 1));
    while (!pq.empty())
    {
        pp v = pq.top();
        // v=dis,node
        pq.pop();
        if (vis[v.second] == 1)
        {
            continue;
        }
        vis[v.second] = 1;
        for (auto i : g[v.second])
        {
            lli weight = i.second;
            lli neigh = i.first;
            if (dis[neigh] > dis[v.second] + weight)
            {
                dis[neigh] = dis[v.second] + weight;
                pq.push(MP(-dis[neigh], neigh));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        lli a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(MP(b, c));
    }
    Dijkstra();

    return 0;
}