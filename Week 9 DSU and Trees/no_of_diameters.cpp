#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<lli, lli>;
int n;
vector<vector<int>> g;
vector<int> parent;
vector<int> depth;
void dfs(int root, int par, int dep)
{
    parent[root] = par;
    depth[root] = dep;
    for (auto v : g[root])
    {
        if (v != par)
        {
            dfs(v, root, dep + 1);
        }
    }
}
int cnt = 0;
int dia_len;
map<int, int> mp1;
map<int, int> mp2;
void dfs2(int root, int par, int dep)
{
    if (dep == dia_len / 2 - 1)
    {
        cnt++;
    }
    parent[root] = par;
    depth[root] = dep;
    for (auto v : g[root])
    {
        if (v != par)
        {
            dfs2(v, root, dep + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << "1";
        return 0;
    }
    g.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0, 0);
    int maxdep_leaf = INT_MIN;
    int maxdep_leaf_index = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxdep_leaf < depth[i])
        {
            maxdep_leaf = depth[i];
            maxdep_leaf_index = i;
        }
    }
    dfs(maxdep_leaf_index, 0, 0);

    int last_point = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > dia_len)
        {
            last_point = i;
            dia_len = depth[i];
        }
    }
    // cout<<"dia len "<<dia_len<<endl;
    int c1, c2;
    int par = last_point;
    for (int i = 1; i <= dia_len / 2; i++)
    {
        par = parent[par];
    }
    c1 = par;
    c2 = parent[c1];
    // cout<<"last point "<<last_point<<endl;
    if (dia_len % 2 == 0)
    { // one center will be there
        for (auto i : g[c1])
        {
            cnt = 0;
            dfs2(i, c1, 0);
            mp1[cnt]++;
        }
    }
    else
    { // two center will be there
        // cout<<"c1:"<<c1<<" c2:"<<c2<<endl;
        for (auto i : g[c1])
        {
            if (i != c2)
            {
                cnt = 0;
                dfs2(i, c1, 0);
                mp1[cnt]++;
            }
        }
        for (auto i : g[c2])
        {
            if (i != c1)
            {
                cnt = 0;
                dfs2(i, c2, 0);
                mp2[cnt]++;
            }
        }
    }
    lli ans = 0;

    if (dia_len % 2 == 1) // two centers
    {
        for (auto &p1 : mp1)
        {
            for (auto &p2 : mp2)
            {
                ans += (lli)p1.first * p2.first * p1.second * p2.second;
            }
        }
    }
    else // one center
    {
        lli total_pairs = 0;
        for (auto &p : mp1)
        {
            total_pairs += (lli)p.first * p.second;
        }
        ans = total_pairs * (total_pairs - 1) / 2;
    }
    cout << ans << endl;

    return 0;

    return 0;
}