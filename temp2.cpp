#include <bits/stdc++.h>
using namespace std;

// Direction vectors for moving in four possible directions: up, down, left, right
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 1e9)); // Initialize distances with a large number (1e9)
    queue<pair<int, int>> q;

    // Reading the grid and initializing the queue with positions of 2s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                vis[i][j] = 0; // Distance to itself is zero
                q.push({i, j});
            }
        }
    }

    // Perform BFS to spread the infection from 2s to 1s
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            // Check if the new position is within bounds and is a cell that can be infected (not 0)
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] != 0 && vis[xx][yy] == 1e9) {
                vis[xx][yy] = vis[x][y] + 1; // Update the distance
                q.push({xx, yy});
            }
        }
    }

    int maxSteps = 0;
    bool unreachable = false;

    // Check the maximum steps required to infect all 1s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                if (vis[i][j] == 1e9) {
                    unreachable = true; // There is a 1 that couldn't be reached
                } else {
                    maxSteps = max(maxSteps, vis[i][j]); // Update the maximum steps required
                }
            }
        }
    }

    if (unreachable) {
        cout << -1 << endl; // Output -1 if any 1 could not be infected
    } else {
        cout << maxSteps << endl; // Output the maximum steps required to infect all 1s
    }

    return 0;
}