#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<int, int>;
vector<vector<int>> matrix;
vector<vector<int>> vis;
vector<vector<int>> color;
vector<int> color_count;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int x, int y)
{
    if (x <= n && y <= m && matrix[x][y] != 1 && x >= 1 && y >= 1)
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
void bfs(pp node, int curr_color)
{
    queue<pp> q;
    q.push(node);
    vis[node.first][node.second] = 1;
    color[node.first][node.second] = curr_color;
    color_count[curr_color]++;

    while (!q.empty())
    {
        pp ele = q.front();
        q.pop();
        for (auto i : neighbour(ele))
        {
            if (!vis[i.first][i.second])
            {
                color[i.first][i.second] = curr_color;
                vis[i.first][i.second] = 1;
                color_count[curr_color]++;
                q.push(make_pair(i.first, i.second));
            }
        }
    }
}

void solve()
{
    matrix.clear();
    vis.clear();
    color.clear();
    color_count.clear();
    cin >> n >> m;
    matrix.assign(n + 1, vector<int>(m + 1));
    vis.assign(n + 1, vector<int>(m + 1, 0));
    color.assign(n + 1, vector<int>(m + 1, 0));
    color_count.assign(n * m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int curr_color = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && matrix[i][j] != 1)
            {
                curr_color++;

                bfs(make_pair(i, j), curr_color);
            }
        }
    }
    // editing matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (matrix[i][j] != 1)
            {
                int col = color[i][j];
                int num = color_count[col];
                if (num != 1)
                {
                    matrix[i][j] = num;
                }
            }
        }
    }
    // printing matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

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