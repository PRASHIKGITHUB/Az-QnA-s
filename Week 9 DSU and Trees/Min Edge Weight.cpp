#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;

vector<int> sz;
vector<int> parent;
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
void merge(int a, int b)
{
    a = rep(a);
    b = rep(b);
    if (a == b)
    {
        return;
    }
    if (sz[a] > sz[b])
    {
        parent[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a];
    }
}
void solve()
{
    int n;
    cin >> n;
    sz.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i < n; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_pair(w, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    lli ans = 0;
    for (auto e : edges)
    {
        int a = e.second.first;
        int b = e.second.second;
        a = rep(a);
        b = rep(b);
        if (rep(a) != rep(b))
        {
            ans += 1LL * e.first * sz[a] * sz[b];
            merge(a, b);
        }
    }
    cout << ans << endl;
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