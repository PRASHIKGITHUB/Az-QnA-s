#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
vector<pair<int, int>> edge_ordering;
vector<pair<int, int>> reverse_query;
vector<int> edges;
vector<int> parent;
vector<int> sz;
vector<int> ans;
int n, m, q;
int components;
int rep(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = rep(parent[x]);
    }
}
void add(int a, int b)
{
    a = rep(a);
    b = rep(b);
    if (a == b)
    {
        return;
    }
    if (sz[a] >= sz[b])
    {
        parent[b] = a;
        sz[a] += sz[b];
        components--;
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a];
        components--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    components = n;
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge_ordering.push_back(make_pair(a, b));
        edges.push_back(i); // it will store all the edges
    }
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 2)
        {
            reverse_query.push_back({2, 0});
        }
        else
        {
            int b;
            cin >> b;
            reverse_query.push_back({1, b});
            auto i = find(edges.begin(), edges.end(), b);
            if (i != edges.end())
            {
                edges.erase(i); // removing all the eges that will get removed in queries
            }
        }
    }
    // now edges will contain all the edges which aren't going to get removed(initial state)
    reverse(reverse_query.begin(), reverse_query.end());
    // add all the edges to the graph from edges vector
    for (auto e : edges)
    {
        pair<int, int> p = edge_ordering[e - 1];
        add(p.first, p.second);
    }
    for (auto q : reverse_query)
    {
        if (q.first == 2)
        {
            ans.push_back(components);
        }
        else
        {
            pair<int, int> edge_to_add = edge_ordering[q.second - 1];
            add(edge_to_add.first, edge_to_add.second);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}