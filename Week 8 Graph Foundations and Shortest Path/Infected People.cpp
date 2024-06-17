#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n, m;
vector<vector<int>> vis;
vector<vector<int>> grid;
vector<vector<int>> closest_infected_person_distance;
vector<pair<int, int>> infected_people;
vector<pair<int, int>> not_infected_people;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int type = 1;
bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0)
    {
        return true;
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
        if (check(X, Y) && !vis[X][Y]) // check if the cell is already visited or not
        {
            ans.push_back(make_pair(X, Y));
        }
    }
    return ans;
}

void Multi_source_bfs(vector<pair<int, int>> &monstors)
{
    queue<pair<int, int>> q;

    for (auto i : monstors)
    {
        q.push(i);
        vis[i.first][i.second] = 1;
        closest_infected_person_distance[i.first][i.second] = 0;
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
                closest_infected_person_distance[i.first][i.second] = closest_infected_person_distance[v.first][v.second] + 1;
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
    vis.assign(n, vector<int>(m, 0));
    grid.assign(n, vector<int>(m, 0));
    closest_infected_person_distance.assign(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
            {
                infected_people.push_back(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
            {
                not_infected_people.push_back(make_pair(i, j));
            }
        }
    }
    Multi_source_bfs(infected_people);
    int ans = INT_MIN;
    for (auto i : not_infected_people)
    {
        ans = max(ans, closest_infected_person_distance[i.first][i.second]);
    }
    if (not_infected_people.size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    if (ans != 1e9)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}