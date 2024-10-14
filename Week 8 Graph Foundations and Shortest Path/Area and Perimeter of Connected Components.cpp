#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli = long long int;
int n;
vector<string> g;
vector<pair<int, int>> area_perimeter;
vector<vector<int>> vis;
int min_perimeter_for_max_area = INT_MAX;
int max_area = INT_MIN;
int area_cnt = 0;
int perimeter_cnt = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int x, int y)
{
    if ((x >= 0 && y >= 0 && x < n && y < n && g[x][y] == '.') || (x == n || x == -1 || y == n || y == -1))
    {
        perimeter_cnt++;
    }
    if (x >= 0 && y >= 0 && x < n && y < n && g[x][y] == '#')
    {
        return true;
    }
    return false;
}
vector<pair<int, int>> neighbour(pair<int, int> p)
{
    vector<pair<int, int>> ans;
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
void bfs(pair<int, int> node)
{
    area_cnt = 1;
    // cout<<"bfs started"<<endl;
    perimeter_cnt = 0;
    vis[node.first][node.second] = 1;
    queue<pair<int, int>> q;
    q.push(node);
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (auto i : neighbour(p))
        {
            if (vis[i.first][i.second] == 0)
            {
                vis[i.first][i.second] = 1;
                area_cnt++;
                q.push(i);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    max_area = max(max_area, area_cnt);
    area_perimeter.emplace_back(make_pair(area_cnt, perimeter_cnt));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.assign(n, "");
    vis.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && g[i][j] == '#')
            {
                bfs(make_pair(i, j));
            }
        }
    }
    sort(area_perimeter.begin(), area_perimeter.end());
    for (auto i : area_perimeter)
    {
        // cout<<i.first<<" "<<i.second<<endl;
        if (i.first == max_area)
        {
            min_perimeter_for_max_area = min(min_perimeter_for_max_area, i.second);
        }
    }

    if (max_area == INT_MAX)
    {
        cout << "0 0" << endl;
    }
    else
    {
        cout << max_area << " " << min_perimeter_for_max_area << endl;
    }

    return 0;
}

// 6
// ##....
// ....#.
// .#..#.
// .#####
// ...###
// ....##