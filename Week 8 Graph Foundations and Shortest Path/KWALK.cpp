#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
using pp = pair<int, int>;
vector<vector<int>> dis;
vector<vector<int>> vis;
int N, Sx, Sy, Fx, Fy;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool check(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= N && y <= N)
    {
        return true;
    }
    return false;
}

vector<pp> neighbour(pp p)
{
    vector<pp> ans;
    for (int i = 0; i < 8; i++)
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
            if (!vis[i.first][i.second])//could have done just by using dis
            {
                vis[i.first][i.second] = 1;
                q.push(make_pair(i.first, i.second));
                dis[i.first][i.second] = dis[ele.first][ele.second] + 1;
            }
        }
    }
}

void solve()
{
    dis.clear();
    vis.clear();
    cin >> N >> Sx >> Sy >> Fx >> Fy;

    dis.assign(N + 1, vector<int>(N + 1, 0));
    vis.assign(N + 1, vector<int>(N + 1, 0));
    if (Sx == Fx && Sy == Fy)
    {
        cout << "0" << endl;
        return;
    }
    bfs(make_pair(Sx, Sy));
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    if (dis[Fx][Fy] != 0)
    {
        cout << dis[Fx][Fy] << endl;
    }
    else
    {
        cout << "-1" << endl;
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
