#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis;
void bfs(int node)
{
    dis[node] = 0;
    deque<int> q;
    q.push_back(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop_front();
        for (auto i : g[temp])
        {
            int neigh = i.first;
            int weight = i.second;
            if (dis[neigh] > dis[temp] + weight)
            {
                dis[neigh] = dis[temp] + weight;
                if (weight == 0)
                {
                    q.push_front(neigh);
                }
                else
                {
                    q.push_back(neigh);
                }

                //in case of normal bfs q.push(neigh) would be there
            }
        }
    }
    if (dis[n] == 1e9)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }
}
void solve()
{
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    dis.clear();
    dis.assign(n + 1, 1e9);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            continue;
        }
        g[a].push_back(make_pair(b, 0));
        g[b].push_back(make_pair(a, 1));
    }
    bfs(1);
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
    }
    return 0;
}