#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<int, int>;
vector<string> building;
vector<vector<int>> vis;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int x, int y)
{
    if (x < n && y < m && x >= 0 && y >= 0 && building[x][y] != '#')
    {
        return 1;
    }
    return false;
}
vector<pp> neighbour(pp p)
{
    vector<pp> ans;
    for (int i = 0; i < 4; i++)
    {
        int x = p.first + dx[i];
        int y = p.second + dy[i];
        if (check(x, y))
        {
            ans.push_back(make_pair(x, y));
        }
    }
    return ans;
}
void bfs(pp node)
{
    queue<pp> q;
    q.push(node);
    vis[node.first][node.second] = 1;

    while (!q.empty())
    {
        pp ele = q.front();
        q.pop();
        for (auto i : neighbour(ele))
        {
            if (!vis[i.first][i.second])
            {
                vis[i.first][i.second] = 1;
                q.push(make_pair(i.first, i.second));
            }
        }
    }
}

void solve()
{
    building.clear();
    vis.clear();
    cin >> n >> m;
    building.assign(n, "");
    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> building[i];
    }

    int curr_color = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && building[i][j] != '#')
            {
                curr_color++;
                bfs(make_pair(i, j));
            }
        }
    }
    cout << curr_color;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}