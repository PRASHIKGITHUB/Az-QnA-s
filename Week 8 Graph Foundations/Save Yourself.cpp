#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n, m;
vector<vector<int>> vis;
vector<string> grid;
vector<vector<int>> dis;
vector<vector<int>> closest_monstor_distance;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int type = 1;
bool check(int x, int y)
{
    if (type == 1)
    {
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && grid[x][y] != 'M')
        {
            return true;
        }
    }
    else if (type == 2)
    {
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#')
        {
            return true;
        }
    }

    return false;
}
vector<pair<int, int>> neighbour(int x, int y)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (check(X, Y))
        {
            ans.push_back(make_pair(X, Y));
        }
    }
    return ans;
}
void bfs(pair<int, int> node)
{
    queue<pair<int, int>> q;
    q.push(node);
    vis[node.first][node.second] = 1;
    dis[node.first][node.second] = 0;
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        for (auto i : neighbour(v.first, v.second))
        {
            if (!vis[i.first][i.second])
            {
                vis[i.first][i.second] = 1;
                q.push(i);
                dis[i.first][i.second] = dis[v.first][v.second] + 1;
            }
        }
    }
}
void Multi_source_bfs(vector<pair<int, int>> &monstors)
{
    queue<pair<int, int>> q;

    for (auto i : monstors)
    {
        q.push(i);
        vis[i.first][i.second] = 1;
        closest_monstor_distance[i.first][i.second] = 0;
    }
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        for (auto i : neighbour(v.first, v.second))
        {
            if (!vis[i.first][i.second])
            {
                vis[i.first][i.second] = 1;
                q.push(i);
                closest_monstor_distance[i.first][i.second] = closest_monstor_distance[v.first][v.second] + 1;
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
    grid.resize(n);
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    pair<int, int> S;
    vector<pair<int, int>> monstors;
    vector<pair<int, int>> valid_boundry_cell;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                S = make_pair(i, j);
            }
            if (grid[i][j] == 'M')
            {
                monstors.push_back(make_pair(i, j));
            }
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1 && grid[i][j] != '#' && grid[i][j] != 'M')
            {
                valid_boundry_cell.push_back(make_pair(i, j));
            }
        }
    }
    bfs(S);
    
    type = 2;
    vis.assign(n, vector<int>(m, 0));
    closest_monstor_distance.assign(n, vector<int>(m, 1e9));
    Multi_source_bfs(monstors);
    int ans = INT_MAX;
    for (auto i : valid_boundry_cell)
    {
        if (dis[i.first][i.second] < closest_monstor_distance[i.first][i.second])
        {
            ans = min(ans, dis[i.first][i.second]);
        }
    }
    if (ans != INT_MAX)
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}